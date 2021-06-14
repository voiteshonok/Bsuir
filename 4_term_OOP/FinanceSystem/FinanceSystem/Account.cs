using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace FinanceSystem
{
    public class Account
    {
        private delegate void Message(string message);
        private event Message IPut;
        private event Message ITake;
        public int Sum {get; private set;}

        public Account(int sum)
        {
            Sum = sum;
            IPut = (str) => MessageBox.Show(str);
            ITake = (str) => MessageBox.Show(str);
        }

        public void Put(int delta)
        {
            if (delta < 0)
            {
                throw new InvalidOperationException("delta is less than zero");
            }
            Sum += delta;

            IPut?.Invoke($"Putted {delta}");
        }

        public void Take(int delta)
        {
            if (delta < 0)
            {
                throw new InvalidOperationException("delta is less than zero");
            }
            if (Sum - delta < 0)
            {
                throw new InvalidOperationException("insufficient funds");
            }
            else
            {
                Sum -= delta;
            }

            ITake?.Invoke($"Taken {delta}");
        }
    }
}
