using System;
using System.Collections.Generic;
using System.Text;

namespace FinanceSystem
{
    public abstract class Person
    {
        public string login { get; set; }
        public string password { get; set; }

        public Account account { get; set; }

        public Person(string login, string password, Account account)
        {
            this.login = login;
            this.password = password;
            this.account = account;
        }

        public Person(string login, string password)
        {
            this.login = login;
            this.password = password;
        }

        abstract public void Execute();
    }
}
