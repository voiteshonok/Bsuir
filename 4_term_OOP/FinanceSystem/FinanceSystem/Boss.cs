using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace FinanceSystem
{
    public class Boss: Person
    {
        public Boss(string login, string password, Account account) : base(login, password, account)
        {

        }

        public override void Execute()
        {
            Thread thread = new Thread(() => ThreadStart(this));
            thread.TrySetApartmentState(ApartmentState.STA);
            thread.Start();
        }
        private static void ThreadStart(Boss boss)
        {
            Application.Run(new BossForm(boss));
        }

        public void PaySalary()
        {
            var accountToWork = DB.AccountToWork();
            foreach (var account in accountToWork.Keys)
            {
                account.Put(200 + accountToWork[account] * 10);
            }
        }
    }
}
