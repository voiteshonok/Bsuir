namespace FinanceSystem
{
    partial class ClientForm
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
            this.textBoxLogin = new System.Windows.Forms.TextBox();
            this.textBoxPassword = new System.Windows.Forms.TextBox();
            this.textBoxYRSpecip = new System.Windows.Forms.TextBox();
            this.textBoxTopUp = new System.Windows.Forms.TextBox();
            this.buttonTopUp = new System.Windows.Forms.Button();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.YRtabPage = new System.Windows.Forms.TabPage();
            this.buttonYRRequest = new System.Windows.Forms.Button();
            this.comboBoxYR = new System.Windows.Forms.ComboBox();
            this.PHIStabPage = new System.Windows.Forms.TabPage();
            this.buttonPHISRequest = new System.Windows.Forms.Button();
            this.comboBoxPHIS = new System.Windows.Forms.ComboBox();
            this.textBoxPHISSpecip = new System.Windows.Forms.TextBox();
            this.tabControl1.SuspendLayout();
            this.YRtabPage.SuspendLayout();
            this.PHIStabPage.SuspendLayout();
            this.SuspendLayout();
            // 
            // textBoxLogin
            // 
            this.textBoxLogin.Enabled = false;
            this.textBoxLogin.Location = new System.Drawing.Point(129, 21);
            this.textBoxLogin.Name = "textBoxLogin";
            this.textBoxLogin.Size = new System.Drawing.Size(154, 31);
            this.textBoxLogin.TabIndex = 0;
            // 
            // textBoxPassword
            // 
            this.textBoxPassword.Enabled = false;
            this.textBoxPassword.Location = new System.Drawing.Point(362, 21);
            this.textBoxPassword.Name = "textBoxPassword";
            this.textBoxPassword.Size = new System.Drawing.Size(154, 31);
            this.textBoxPassword.TabIndex = 0;
            // 
            // textBoxYRSpecip
            // 
            this.textBoxYRSpecip.Enabled = false;
            this.textBoxYRSpecip.Location = new System.Drawing.Point(75, 150);
            this.textBoxYRSpecip.Multiline = true;
            this.textBoxYRSpecip.Name = "textBoxYRSpecip";
            this.textBoxYRSpecip.Size = new System.Drawing.Size(574, 63);
            this.textBoxYRSpecip.TabIndex = 1;
            // 
            // textBoxTopUp
            // 
            this.textBoxTopUp.Location = new System.Drawing.Point(355, 85);
            this.textBoxTopUp.Name = "textBoxTopUp";
            this.textBoxTopUp.Size = new System.Drawing.Size(196, 31);
            this.textBoxTopUp.TabIndex = 1;
            // 
            // buttonTopUp
            // 
            this.buttonTopUp.Location = new System.Drawing.Point(602, 85);
            this.buttonTopUp.Name = "buttonTopUp";
            this.buttonTopUp.Size = new System.Drawing.Size(112, 34);
            this.buttonTopUp.TabIndex = 2;
            this.buttonTopUp.Text = "Top Up";
            this.buttonTopUp.UseVisualStyleBackColor = true;
            this.buttonTopUp.Click += new System.EventHandler(this.buttonTopUp_Click);
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.YRtabPage);
            this.tabControl1.Controls.Add(this.PHIStabPage);
            this.tabControl1.Location = new System.Drawing.Point(90, 284);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(832, 269);
            this.tabControl1.TabIndex = 3;
            this.tabControl1.SelectedIndexChanged += new System.EventHandler(this.tabControl1_SelectedIndexChanged);
            // 
            // YRtabPage
            // 
            this.YRtabPage.Controls.Add(this.buttonYRRequest);
            this.YRtabPage.Controls.Add(this.comboBoxYR);
            this.YRtabPage.Controls.Add(this.textBoxYRSpecip);
            this.YRtabPage.Location = new System.Drawing.Point(4, 34);
            this.YRtabPage.Name = "YRtabPage";
            this.YRtabPage.Padding = new System.Windows.Forms.Padding(3);
            this.YRtabPage.Size = new System.Drawing.Size(824, 231);
            this.YRtabPage.TabIndex = 0;
            this.YRtabPage.Text = "YRtabPage";
            this.YRtabPage.UseVisualStyleBackColor = true;
            // 
            // buttonYRRequest
            // 
            this.buttonYRRequest.Location = new System.Drawing.Point(479, 31);
            this.buttonYRRequest.Name = "buttonYRRequest";
            this.buttonYRRequest.Size = new System.Drawing.Size(112, 34);
            this.buttonYRRequest.TabIndex = 2;
            this.buttonYRRequest.Text = "Request";
            this.buttonYRRequest.UseVisualStyleBackColor = true;
            this.buttonYRRequest.Click += new System.EventHandler(this.buttonYRRequest_Click);
            // 
            // comboBoxYR
            // 
            this.comboBoxYR.FormattingEnabled = true;
            this.comboBoxYR.Location = new System.Drawing.Point(75, 30);
            this.comboBoxYR.Name = "comboBoxYR";
            this.comboBoxYR.Size = new System.Drawing.Size(305, 33);
            this.comboBoxYR.TabIndex = 0;
            this.comboBoxYR.SelectedIndexChanged += new System.EventHandler(this.comboBoxYR_SelectedIndexChanged);
            // 
            // PHIStabPage
            // 
            this.PHIStabPage.Controls.Add(this.buttonPHISRequest);
            this.PHIStabPage.Controls.Add(this.comboBoxPHIS);
            this.PHIStabPage.Controls.Add(this.textBoxPHISSpecip);
            this.PHIStabPage.Location = new System.Drawing.Point(4, 34);
            this.PHIStabPage.Name = "PHIStabPage";
            this.PHIStabPage.Padding = new System.Windows.Forms.Padding(3);
            this.PHIStabPage.Size = new System.Drawing.Size(824, 231);
            this.PHIStabPage.TabIndex = 1;
            this.PHIStabPage.Text = "PHIStabPage";
            this.PHIStabPage.UseVisualStyleBackColor = true;
            // 
            // buttonPHISRequest
            // 
            this.buttonPHISRequest.Location = new System.Drawing.Point(479, 31);
            this.buttonPHISRequest.Name = "buttonPHISRequest";
            this.buttonPHISRequest.Size = new System.Drawing.Size(112, 34);
            this.buttonPHISRequest.TabIndex = 2;
            this.buttonPHISRequest.Text = "Request";
            this.buttonPHISRequest.UseVisualStyleBackColor = true;
            this.buttonPHISRequest.Click += new System.EventHandler(this.buttonPHISRequest_Click);
            // 
            // comboBoxPHIS
            // 
            this.comboBoxPHIS.FormattingEnabled = true;
            this.comboBoxPHIS.Location = new System.Drawing.Point(75, 30);
            this.comboBoxPHIS.Name = "comboBoxPHIS";
            this.comboBoxPHIS.Size = new System.Drawing.Size(305, 33);
            this.comboBoxPHIS.TabIndex = 4;
            this.comboBoxPHIS.SelectedIndexChanged += new System.EventHandler(this.comboBoxPHIS_SelectedIndexChanged);
            // 
            // textBoxPHISSpecip
            // 
            this.textBoxPHISSpecip.Enabled = false;
            this.textBoxPHISSpecip.Location = new System.Drawing.Point(75, 150);
            this.textBoxPHISSpecip.Multiline = true;
            this.textBoxPHISSpecip.Name = "textBoxPHISSpecip";
            this.textBoxPHISSpecip.Size = new System.Drawing.Size(574, 63);
            this.textBoxPHISSpecip.TabIndex = 1;
            // 
            // ClientForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1028, 565);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.buttonTopUp);
            this.Controls.Add(this.textBoxTopUp);
            this.Controls.Add(this.textBoxPassword);
            this.Controls.Add(this.textBoxLogin);
            this.Name = "ClientForm";
            this.Text = "ClentForm";
            this.tabControl1.ResumeLayout(false);
            this.YRtabPage.ResumeLayout(false);
            this.YRtabPage.PerformLayout();
            this.PHIStabPage.ResumeLayout(false);
            this.PHIStabPage.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Client client;
        private System.Windows.Forms.TextBox textBoxLogin;
        private System.Windows.Forms.TextBox textBoxPassword;
        private System.Windows.Forms.TextBox textBoxYRSpecip;
        private System.Windows.Forms.TextBox textBoxTopUp;
        private System.Windows.Forms.Button buttonTopUp;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage YRtabPage;
        private System.Windows.Forms.ComboBox comboBoxYR;
        private System.Windows.Forms.TabPage PHIStabPage;
        private System.Windows.Forms.ComboBox comboBoxPHIS;
        private System.Windows.Forms.Button buttonYRRequest;
        private System.Windows.Forms.Button buttonPHISRequest;
        private System.Windows.Forms.TextBox textBoxPHISSpecip;
    }
}