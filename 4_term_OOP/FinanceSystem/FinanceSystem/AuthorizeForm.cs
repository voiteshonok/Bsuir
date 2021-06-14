using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FinanceSystem
{
    public partial class AuthorizeForm : Form
    {
        public AuthorizeForm()
        {
            InitializeComponent();
        }

        private void buttonIn_Click(object sender, EventArgs e)
        {
            var login = this.textBoxLogin.Text;
            var password = this.textBoxPassword.Text;

            DB.GetPerson(login, password)?.Execute();
        }

        private void buttonUp_Click(object sender, EventArgs e)
        {
            var login = this.textBoxLogin.Text;
            var password = this.textBoxPassword.Text;

            DB.GetPerson(login, password)?.Execute();

            DB.MakeClient(login, password)?.Execute();
        }
    }
}
