using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace FinanceSystem
{
    public class Client : Person
    {
        public Client(string login, string password, Account account) : base(login, password, account)
        {

        }

        public override void Execute()
        {
            Thread thread = new Thread(() => ThreadStart(this));
            thread.TrySetApartmentState(ApartmentState.STA);
            thread.Start();
        }
        private static void ThreadStart(Client client)
        {
            Application.Run(new ClientForm(client));
        }
    }
}
