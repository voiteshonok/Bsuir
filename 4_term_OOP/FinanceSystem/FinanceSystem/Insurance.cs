using System;
using System.Collections.Generic;
using System.Text;

namespace FinanceSystem
{
    public class Insurance
    {
        public string type { get; private set; }
        public string spec { get; private set; }
        public int cost { get; private set; }

        public string info { get; private set; }

        public Insurance(string spec, string type, int cost, string info)
        {
            this.spec = spec;
            this.type = type;
            this.cost = cost;
            this.info = info;
        }
    }
}
