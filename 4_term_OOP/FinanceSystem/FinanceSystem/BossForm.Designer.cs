namespace FinanceSystem
{
    partial class BossForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.buttonPay = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonAddPeson = new System.Windows.Forms.Button();
            this.textBoxPassword = new System.Windows.Forms.TextBox();
            this.textBoxLogin = new System.Windows.Forms.TextBox();
            this.textBoxInsuranceSpec = new System.Windows.Forms.TextBox();
            this.textBoxInsuranceType = new System.Windows.Forms.TextBox();
            this.textBoxInsuranceCost = new System.Windows.Forms.TextBox();
            this.buttonInsuranceAdd = new System.Windows.Forms.Button();
            this.textBoxInsuranceInfo = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.label6 = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // buttonPay
            // 
            this.buttonPay.Location = new System.Drawing.Point(118, 26);
            this.buttonPay.Name = "buttonPay";
            this.buttonPay.Size = new System.Drawing.Size(159, 57);
            this.buttonPay.TabIndex = 0;
            this.buttonPay.Text = "Pay Salary";
            this.buttonPay.UseVisualStyleBackColor = true;
            this.buttonPay.Click += new System.EventHandler(this.buttonPay_Click);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.buttonAddPeson);
            this.panel1.Controls.Add(this.textBoxPassword);
            this.panel1.Controls.Add(this.textBoxLogin);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Right;
            this.panel1.Location = new System.Drawing.Point(587, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(311, 522);
            this.panel1.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(19, 138);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(93, 25);
            this.label2.TabIndex = 3;
            this.label2.Text = "password:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(19, 58);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(56, 25);
            this.label1.TabIndex = 2;
            this.label1.Text = "login:";
            // 
            // buttonAddPeson
            // 
            this.buttonAddPeson.Location = new System.Drawing.Point(192, 96);
            this.buttonAddPeson.Name = "buttonAddPeson";
            this.buttonAddPeson.Size = new System.Drawing.Size(112, 111);
            this.buttonAddPeson.TabIndex = 1;
            this.buttonAddPeson.Text = "Add Employee";
            this.buttonAddPeson.UseVisualStyleBackColor = true;
            this.buttonAddPeson.Click += new System.EventHandler(this.buttonAddPeson_Click);
            // 
            // textBoxPassword
            // 
            this.textBoxPassword.Location = new System.Drawing.Point(19, 176);
            this.textBoxPassword.Name = "textBoxPassword";
            this.textBoxPassword.Size = new System.Drawing.Size(150, 31);
            this.textBoxPassword.TabIndex = 0;
            // 
            // textBoxLogin
            // 
            this.textBoxLogin.Location = new System.Drawing.Point(19, 100);
            this.textBoxLogin.Name = "textBoxLogin";
            this.textBoxLogin.Size = new System.Drawing.Size(150, 31);
            this.textBoxLogin.TabIndex = 0;
            // 
            // textBoxInsuranceSpec
            // 
            this.textBoxInsuranceSpec.Location = new System.Drawing.Point(81, 16);
            this.textBoxInsuranceSpec.Multiline = true;
            this.textBoxInsuranceSpec.Name = "textBoxInsuranceSpec";
            this.textBoxInsuranceSpec.Size = new System.Drawing.Size(150, 76);
            this.textBoxInsuranceSpec.TabIndex = 2;
            // 
            // textBoxInsuranceType
            // 
            this.textBoxInsuranceType.Location = new System.Drawing.Point(81, 159);
            this.textBoxInsuranceType.Name = "textBoxInsuranceType";
            this.textBoxInsuranceType.Size = new System.Drawing.Size(150, 31);
            this.textBoxInsuranceType.TabIndex = 3;
            // 
            // textBoxInsuranceCost
            // 
            this.textBoxInsuranceCost.Location = new System.Drawing.Point(397, 159);
            this.textBoxInsuranceCost.Name = "textBoxInsuranceCost";
            this.textBoxInsuranceCost.Size = new System.Drawing.Size(150, 31);
            this.textBoxInsuranceCost.TabIndex = 4;
            // 
            // buttonInsuranceAdd
            // 
            this.buttonInsuranceAdd.Location = new System.Drawing.Point(224, 229);
            this.buttonInsuranceAdd.Name = "buttonInsuranceAdd";
            this.buttonInsuranceAdd.Size = new System.Drawing.Size(112, 82);
            this.buttonInsuranceAdd.TabIndex = 5;
            this.buttonInsuranceAdd.Text = "Add Insurance";
            this.buttonInsuranceAdd.UseVisualStyleBackColor = true;
            this.buttonInsuranceAdd.Click += new System.EventHandler(this.buttonInsuranceAdd_Click);
            // 
            // textBoxInsuranceInfo
            // 
            this.textBoxInsuranceInfo.Location = new System.Drawing.Point(371, 16);
            this.textBoxInsuranceInfo.Multiline = true;
            this.textBoxInsuranceInfo.Name = "textBoxInsuranceInfo";
            this.textBoxInsuranceInfo.Size = new System.Drawing.Size(195, 76);
            this.textBoxInsuranceInfo.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(23, 16);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(52, 25);
            this.label3.TabIndex = 7;
            this.label3.Text = "spec:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(289, 159);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(49, 25);
            this.label4.TabIndex = 8;
            this.label4.Text = "cost:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(289, 19);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(47, 25);
            this.label5.TabIndex = 9;
            this.label5.Text = "info:";
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.SystemColors.GrayText;
            this.panel2.Controls.Add(this.label6);
            this.panel2.Controls.Add(this.buttonInsuranceAdd);
            this.panel2.Controls.Add(this.textBoxInsuranceType);
            this.panel2.Controls.Add(this.label5);
            this.panel2.Controls.Add(this.label3);
            this.panel2.Controls.Add(this.textBoxInsuranceInfo);
            this.panel2.Controls.Add(this.label4);
            this.panel2.Controls.Add(this.textBoxInsuranceSpec);
            this.panel2.Controls.Add(this.textBoxInsuranceCost);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel2.Location = new System.Drawing.Point(0, 176);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(587, 346);
            this.panel2.TabIndex = 10;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(24, 159);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(51, 25);
            this.label6.TabIndex = 10;
            this.label6.Text = "type:";
            // 
            // BossForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(898, 522);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.buttonPay);
            this.Name = "BossForm";
            this.Text = "BossForm";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private Boss boss;
        private System.Windows.Forms.Button buttonPay;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.TextBox textBoxPassword;
        private System.Windows.Forms.TextBox textBoxLogin;
        private System.Windows.Forms.Button buttonAddPeson;
        private System.Windows.Forms.TextBox textBoxInsuranceSpec;
        private System.Windows.Forms.TextBox textBoxInsuranceType;
        private System.Windows.Forms.TextBox textBoxInsuranceCost;
        private System.Windows.Forms.Button buttonInsuranceAdd;
        private System.Windows.Forms.TextBox textBoxInsuranceInfo;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label label6;
    }
}