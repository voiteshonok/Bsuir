﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.ServiceProcess;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace _2Lab
{
    public partial class ETL : ServiceBase
    {
        Tracer logger;
        string source = "D:\\" + "Source\\";
        string target = "D:\\" + "Target\\";
        string log = "D:\\" + "logs.txt";
        public ETL()
        {
            InitializeComponent();
        }

        protected override void OnStart(string[] args)
        {
            Directory.CreateDirectory(source);
            Directory.CreateDirectory(target);
            File.Create(log).Close();

            logger = new Tracer(source, target, log);
            Thread loggerThread = new Thread(new ThreadStart(logger.Start));
            loggerThread.Start();
        }

        protected override void OnStop()
        {
            logger.Stop();
            try
            {
                Directory.Delete(source, true);
            }
            catch { }
            try
            {
                Directory.Delete(target, true);
            }
            catch { }
            try
            {
                File.Delete(log);
            }
            catch { }
        }
    }
}
