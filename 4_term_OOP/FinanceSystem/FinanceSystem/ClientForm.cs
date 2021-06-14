using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace FinanceSystem
{
    public partial class ClientForm : Form
    {
        private Dictionary<Insurance, int> insurances;
        public ClientForm(Client client)
        {
            InitializeComponent();
            this.client = client;
            this.textBoxLogin.Text = client.login;
            this.textBoxPassword.Text = client.password;
            InitializeComboBox();
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            try
            {
                client.account.Take(50);
                DB.UpdateAccountByPerson(client);
                DB.AddRequest(client.login, this.textBoxYRSpecip.Text, DateTime.Now);
            }
            catch (InvalidOperationException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void buttonTopUp_Click(object sender, EventArgs e)
        {
            int value;
            if (!String.IsNullOrEmpty(this.textBoxTopUp.Text) && Int32.TryParse(this.textBoxTopUp.Text, out value))
            {
                client.account.Put(value);
                DB.UpdateAccountByPerson(client);
            }
        }

        private void InitializeComboBox()
        {
            if (tabControl1.SelectedTab.Name == "YRtabPage")
            {
                comboBoxYR.Items.Clear();
                insurances = DB.GetInsurances("YR");
                foreach(var i in insurances.Keys)
                {
                    comboBoxYR.Items.Add(i.spec);
                }
            }
            else
            {
                comboBoxPHIS.Items.Clear();
                insurances = DB.GetInsurances("PHIS");
                foreach (var i in insurances.Keys)
                {
                    comboBoxPHIS.Items.Add(i.spec);
                }
            }
        }

        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            InitializeComboBox();
        }

        private void comboBoxYR_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBoxYR.SelectedIndex < 0)
            {
                return;
            }

            Insurance insurance = null;
            int i = 0;
            foreach (var ins in insurances.Keys)
            {
                if (i == comboBoxYR.SelectedIndex)
                {
                    insurance = ins;
                    break;
                }
                if (ins.type == "YR")
                {
                    ++i;
                }
            }

            textBoxYRSpecip.Text = insurance.info;
        }


        private void buttonYRRequest_Click(object sender, EventArgs e)
        {
            if(comboBoxYR.SelectedIndex < 0)
            {
                return;
            }

            Insurance insurance = null;
            int i = 0;
            foreach(var ins in insurances.Keys)
            {
                if (i == comboBoxYR.SelectedIndex && ins.type == "YR")
                {
                    insurance = ins;
                    break;
                }
                if (ins.type == "YR")
                {
                    ++i;
                }
            }

            try
            {
                client.account.Take(insurance.cost);
                DB.UpdateAccountByPerson(client);
                DB.AddRequest(client.login, insurance.spec, DateTime.Now);
            }
            catch (InvalidOperationException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }


        private void buttonPHISRequest_Click(object sender, EventArgs e)
        {
            if (comboBoxPHIS.SelectedIndex < 0)
            {
                return;
            }

            Insurance insurance = null;
            int i = 0;
            foreach (var ins in insurances.Keys)
            {
                if (i == comboBoxPHIS.SelectedIndex && ins.type == "PHIS")
                {
                    insurance = ins;
                    break;
                }
                if (ins.type == "PHIS")
                {
                    ++i;
                }
            }

            try
            {
                client.account.Take(insurance.cost);
                DB.UpdateAccountByPerson(client);
                DB.AddRequest(client.login, insurance.spec, DateTime.Now);
            }
            catch (InvalidOperationException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void comboBoxPHIS_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBoxPHIS.SelectedIndex < 0)
            {
                return;
            }

            Insurance insurance = null;
            int i = 0;
            foreach (var ins in insurances.Keys)
            {
                if (i == comboBoxPHIS.SelectedIndex)
                {
                    insurance = ins;
                    break;
                }
                if (ins.type == "PHIS")
                {
                    ++i;
                }
            }

            textBoxPHISSpecip.Text = insurance.info;
        }
    }
}
