using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Text;

namespace FinanceSystem
{
    public static class DB
    {
        private static string connectionString = "Server=localhost;Database=OOP;Trusted_Connection=True;";
        public static Person GetPerson(string login, string password)
        { 
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                string sqlExpression = $"SELECT * FROM Clients WHERE login='{login}' and password = '{password}'";

                SqlCommand command = new SqlCommand(sqlExpression, connection);
                SqlDataReader reader = command.ExecuteReader();

                if (reader.HasRows)
                {
                    while (reader.Read())
                    {
                        return new Client(reader.GetString(1), reader.GetString(2), GetAccountById(reader.GetInt32(3)));
                    }
                }
                reader.Close();


                sqlExpression = $"SELECT * FROM Employees WHERE login='{login}' and password = '{password}'";

                command = new SqlCommand(sqlExpression, connection);
                reader = command.ExecuteReader();

                if (reader.HasRows) { 
                
                    while (reader.Read()) 
                    {
                        return new Employee(reader.GetString(1), reader.GetString(2), GetAccountById(reader.GetInt32(3)));
                        
                    }
                }

                reader.Close();

                sqlExpression = $"SELECT * FROM Boss WHERE login='{login}' and password = '{password}'";
                command = new SqlCommand(sqlExpression, connection);
                reader = command.ExecuteReader();

                if (reader.HasRows)
                {

                    while (reader.Read())
                    {
                        return new Boss(reader.GetString(1), reader.GetString(2), GetAccountById(reader.GetInt32(3)));

                    }
                }

                reader.Close();

                return null;
            };
        }

        public static Client GetClientById(int id)
        {
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                string sqlExpression = $"SELECT * FROM Clients WHERE id={id}";
                
                SqlCommand command = new SqlCommand(sqlExpression, connection);
                SqlDataReader reader = command.ExecuteReader();

                if (reader.HasRows)
                {
                    while (reader.Read())
                    {
                        return new Client(reader.GetString(1), reader.GetString(2), GetAccountById(reader.GetInt32(3)));
                    }
                }
                reader.Close();
            };

            return null;
        }

        public static List<Pair<int, Request>> GetRequests()
        {
            var requests = new List<Pair<int, Request>>();

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                string sqlExpression = $"SELECT * FROM Requests WHERE status = 'Pending'";

                SqlCommand command = new SqlCommand(sqlExpression, connection);
                SqlDataReader reader = command.ExecuteReader();

                if (reader.HasRows)
                {
                    while (reader.Read())
                    {
                        requests.Add(new Pair<int, Request> {
                            First = reader.GetInt32(0),
                            Second = new Request(reader.GetInt32(1), reader.GetString(2), reader.GetString(3), reader.GetString(4)) 
                        }); 
                    }
                }
                reader.Close();
            };

            return requests;
        }

        public static void AcceptRequest(string employeeLogin, int requestId, DateTime time)
        {            
            string sqlExpression = $"Update Requests Set status = 'Accepted' Where id = {requestId}";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                SqlCommand command = new SqlCommand(sqlExpression, connection);
                command.ExecuteNonQuery();
            }

            int employeeId =1;

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                sqlExpression = $"SELECT * FROM Employees WHERE login='{employeeLogin}'";

                SqlCommand command = new SqlCommand(sqlExpression, connection);
                SqlDataReader reader = command.ExecuteReader();

                reader.Read();
                employeeId = reader.GetInt32(0);
                    
            };

            sqlExpression = $"INSERT INTO AcceptedRequests (request_id, employee_id, time) VALUES({requestId}, {employeeId}, {((DateTimeOffset)time).ToUnixTimeSeconds().ToString()}); ";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                SqlCommand command = new SqlCommand(sqlExpression, connection);
                command.ExecuteNonQuery();
            }
        }

        public static void AddRequest(string clientLogin, string spec, DateTime time)
        {
            int clientId = 0;
            string sqlExpression;

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                sqlExpression = $"SELECT * FROM Clients WHERE login='{clientLogin}'";

                SqlCommand command = new SqlCommand(sqlExpression, connection);
                SqlDataReader reader = command.ExecuteReader();

                
                while (reader.Read())
                {
                    clientId = reader.GetInt32(0);
                    break;
                }
                
                reader.Close();
            }

            sqlExpression = $"INSERT INTO Requests (client_id, specification, status, time) VALUES({clientId}, '{spec}', 'Pending', '{((DateTimeOffset)time).ToUnixTimeSeconds().ToString()}'); ";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                SqlCommand command = new SqlCommand(sqlExpression, connection);
                command.ExecuteNonQuery();
            }
        }

        public static Account GetAccountById(int id)
        {
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                string sqlExpression = $"SELECT * FROM Accounts WHERE id = {id}";

                SqlCommand command = new SqlCommand(sqlExpression, connection);
                SqlDataReader reader = command.ExecuteReader();


                while (reader.Read())
                {
                    return new Account(reader.GetInt32(1));
                }

                reader.Close();
            }
            return null;
        }

        public static void UpdateAccountByPerson(Person person)
        {
            int id=0;
            string where;
            if (person is Client)
            {
                where = "Clients";
            }
            else
            {
                where = "Employees";
            }

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                string sqlExpression = $"SELECT * FROM {where} WHERE login = '{person.login}'";

                SqlCommand command = new SqlCommand(sqlExpression, connection);
                SqlDataReader reader = command.ExecuteReader();


                while (reader.Read())
                {
                    id = reader.GetInt32(0);
                }

                reader.Close();
            }

            UpdateAccountById(id, person.account.Sum);
        }

        public static void UpdateAccountById(int id, int newSum)
        {
            string sqlExpression = $"Update Accounts Set sum = {newSum} Where id = {id}";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                SqlCommand command = new SqlCommand(sqlExpression, connection);
                command.ExecuteNonQuery();
            }
        }

        public static Person MakeClient(string login, string password)
        {
            int AccountId = InsertAccount();
            return GetClientById(InsertClient(login, password, AccountId));
        }

        private static int InsertAccount()
        {
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                string sqlExpression = $"INSERT INTO Accounts (sum) VALUES(0) SELECT SCOPE_IDENTITY()";

                SqlCommand command = new SqlCommand(sqlExpression, connection);
                SqlDataReader reader = command.ExecuteReader();


                while (reader.Read())
                {
                    return (int)reader.GetDecimal(0);
                }

                reader.Close();
            }
            return 0;
        }

        private static int InsertClient(string login, string password, int id)
        {
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                string sqlExpression = $"INSERT INTO Clients (login, password, account_id) VALUES('{login}', '{password}', {id})" + $"SELECT SCOPE_IDENTITY()";

                SqlCommand command = new SqlCommand(sqlExpression, connection);
                SqlDataReader reader = command.ExecuteReader();


                while (reader.Read())
                {
                    return (int)reader.GetDecimal(0);
                }

                reader.Close();
            }
            return 0;
        }

        public static Dictionary<Account, int> AccountToWork()
        {
            var idToAccount = new Dictionary<int, Account>();

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                string sqlExpression = $"SELECT * FROM Employees";

                SqlCommand command = new SqlCommand(sqlExpression, connection);
                SqlDataReader reader = command.ExecuteReader();

                if (reader.HasRows)
                {
                    while (reader.Read())
                    {
                        idToAccount.Add(reader.GetInt32(0), GetAccountById(reader.GetInt32(3)));
                    }
                }
                reader.Close();
            }

            var dict = new Dictionary<Account, int>();

            foreach (var id in idToAccount.Keys)
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();
                    string sqlExpression = $"Select count(*) From AcceptedRequests Where employee_id = {id}";

                    SqlCommand command = new SqlCommand(sqlExpression, connection);
                    SqlDataReader reader = command.ExecuteReader();

                    while (reader.Read())
                    {
                        dict.Add(idToAccount[id], reader.GetInt32(0));
                    }
                    reader.Close();
                }
            }

            return dict;
        }

        public static Dictionary<Insurance, int> GetInsurances(string type)
        {
            var dict = new Dictionary<Insurance, int>();
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                string sqlExpression = $"Select * From Insurances Where type = '{type}'";

                SqlCommand command = new SqlCommand(sqlExpression, connection);
                SqlDataReader reader = command.ExecuteReader();

                while (reader.Read())
                {
                    dict.Add(new Insurance(reader.GetString(1), reader.GetString(2), reader.GetInt32(3), reader.GetString(4)), reader.GetInt32(0));
                }
                reader.Close();
            }

            return dict;
        }

        public static void AddNewEmployee(string login, string password)
        {
            int AccountId = InsertAccount();

            string sqlExpression = $"INSERT INTO Employees (login, password, account_id) VALUES('{login}', '{password}', {AccountId})" + $"SELECT SCOPE_IDENTITY()";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                SqlCommand command = new SqlCommand(sqlExpression, connection);
                command.ExecuteNonQuery();
            }
        }

        public static void AddInsurance(Insurance insurance)
        {
            string sqlExpression = $"INSERT INTO Insurances  VALUES('{insurance.spec}', '{insurance.type}', {insurance.cost}, '{insurance.info}'); ";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                SqlCommand command = new SqlCommand(sqlExpression, connection);
                command.ExecuteNonQuery();
            }
        }
    }
}
