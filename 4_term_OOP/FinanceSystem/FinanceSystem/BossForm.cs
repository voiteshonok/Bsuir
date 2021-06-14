using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace FinanceSystem
{
    public partial class BossForm : Form
    {
        public BossForm(Boss boss)
        {
            InitializeComponent();
            this.boss = boss;
        }

        private void buttonPay_Click(object sender, EventArgs e)
        {
            this.boss.PaySalary();
        }

        private void buttonAddPeson_Click(object sender, EventArgs e)
        {
            if (!String.IsNullOrEmpty(textBoxLogin.Text) && !String.IsNullOrEmpty(textBoxPassword.Text))
            {
                DB.AddNewEmployee(textBoxLogin.Text, textBoxPassword.Text);
            }
        }

        private void buttonInsuranceAdd_Click(object sender, EventArgs e)
        {
            if (!String.IsNullOrEmpty(textBoxInsuranceSpec.Text) && !String.IsNullOrEmpty(textBoxInsuranceType.Text)
                && !String.IsNullOrEmpty(textBoxInsuranceCost.Text) && Int32.TryParse(textBoxInsuranceCost.Text, out int cost)
                && (textBoxInsuranceType.Text == "YR" || textBoxInsuranceType.Text == "PHIS")){
                DB.AddInsurance(new Insurance(textBoxInsuranceSpec.Text, textBoxInsuranceType.Text, cost, textBoxInsuranceInfo.Text));
            }
        }

        
    }
}
