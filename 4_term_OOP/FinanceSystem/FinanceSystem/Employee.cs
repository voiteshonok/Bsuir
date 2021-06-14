using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace FinanceSystem
{
    public class Employee : Person
    {
        public Employee(string login, string password, Account account) : base(login, password, account)
        {

        }
        public override void Execute()
        {
            Thread thread = new Thread(() => ThreadStart(this));
            thread.TrySetApartmentState(ApartmentState.STA);
            thread.Start();
        }
        private static void ThreadStart(Employee employee)
        {
            Application.Run(new EmployeeForm(employee));
        }
    }
}
