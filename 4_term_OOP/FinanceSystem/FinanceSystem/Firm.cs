using System;
using System.Collections.Generic;
using System.Text;

namespace FinanceSystem
{
    class Firm
    {
        private static Account account { get; set; }
        public static readonly int accountId = 5;


        private Firm()
        {
        }

        public static Account GetFirmAccount()
        {
            if (account == null)
            {
                account = DB.GetAccountById(accountId);
            }
            return account;
        }
    }
}
