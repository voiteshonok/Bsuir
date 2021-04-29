using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AudioPlayer
{
    public partial class NamePlayListForm : Form
    {
        /// <summary>
        /// Название плейлиста
        /// </summary>
        public string name = "";

        public NamePlayListForm()
        {
            InitializeComponent();
        }

        private void OkButton_Click(object sender, EventArgs e)
        {
            if (!String.IsNullOrWhiteSpace(textBox.Text))
            {
                name = textBox.Text;
            }
            Close();
        }

        private void CancelButton_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
