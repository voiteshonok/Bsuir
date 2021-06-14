using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace FinanceSystem
{
    public partial class EmployeeForm : Form
    {

        public EmployeeForm(Employee employee)
        {
            InitializeComponent();
            this.employee = employee;
            this.textBoxLogin.Text = employee.login;
            this.textBoxPassword.Text = employee.password;
            UpdateGridRequets();
        }

        private void UpdateGridRequets()
        {
            while (dataGridView1.Rows.Count > 0)
            {
                dataGridView1.Rows.RemoveAt(0);
            }


            this.requests = DB.GetRequests();

            foreach (var request in requests)
            {
                dataGridView1.Rows.Add(request.Second.Client.login, request.Second.Specification, request.Second.Status, request.Second.time.ToString());
            }
        }

        private void dataGridView1_RowHeaderMouseClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            var firmAccount = Firm.GetFirmAccount();
            firmAccount.Put(50);
            DB.UpdateAccountById(Firm.accountId, firmAccount.Sum);
            // update employee pay

            DB.AcceptRequest(employee.login, requests[dataGridView1.CurrentCell.RowIndex].First, DateTime.Now);
            //MessageBox.Show(dataGridView1.CurrentCell.RowIndex.ToString());
            UpdateGridRequets();
        }
    }
}
