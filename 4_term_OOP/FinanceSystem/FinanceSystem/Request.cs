using System;
using System.Collections.Generic;
using System.Text;

namespace FinanceSystem
{
    public class Request
    {
        public Client Client { get; set; }
        public string Specification { get; set; }

        public string Status { get; set; }

        public DateTime time { get; set; }

        public Request(Client client, string specifications, string status, string dateTime)
        {
            this.Client = client;
            this.Specification = specifications;
            this.Status = status;
            this.time = UnixTimeStampToDateTime(Double.Parse(dateTime));
        }

        public Request(int id, string specifications, string status, string dateTime):this(DB.GetClientById(id), specifications, status, dateTime)
        {
        }

        private static DateTime UnixTimeStampToDateTime(double unixTimeStamp)
        {
            // Unix timestamp is seconds past epoch
            System.DateTime dtDateTime = new DateTime(1970, 1, 1, 0, 0, 0, 0, System.DateTimeKind.Utc);
            dtDateTime = dtDateTime.AddSeconds(unixTimeStamp).ToLocalTime();
            return dtDateTime;
        }
    }
}
