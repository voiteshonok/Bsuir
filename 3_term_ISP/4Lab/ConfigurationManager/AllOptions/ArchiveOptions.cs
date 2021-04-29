﻿using ConfigurationManager.Options;
using System;
using System.Collections.Generic;
using System.IO.Compression;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3Lab
{
    public class ArchiveOptions : Options
    {
        public CompressionLevel CompressionLevel { get; set; } = CompressionLevel.Optimal;
    }
}
