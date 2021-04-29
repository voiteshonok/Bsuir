namespace AudioPlayer
{
    partial class MainForm
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.PlaylistsListBox = new System.Windows.Forms.ListBox();
            this.SongsListBox = new System.Windows.Forms.ListBox();
            this.PlayButton = new System.Windows.Forms.Button();
            this.PauseButton = new System.Windows.Forms.Button();
            this.SongTrackBar = new System.Windows.Forms.TrackBar();
            this.VolumeTrackBar = new System.Windows.Forms.TrackBar();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.timer = new System.Windows.Forms.Timer(this.components);
            this.CurrentTimeLabel = new System.Windows.Forms.Label();
            this.EntireTimeLabel = new System.Windows.Forms.Label();
            this.AddPlaylistButton = new System.Windows.Forms.Button();
            this.AddSongButton = new System.Windows.Forms.Button();
            this.PlayNextButton = new System.Windows.Forms.Button();
            this.PlayPrevButton = new System.Windows.Forms.Button();
            this.VolumeButton = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel2 = new System.Windows.Forms.Panel();
            ((System.ComponentModel.ISupportInitialize)(this.SongTrackBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.VolumeTrackBar)).BeginInit();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // PlaylistsListBox
            // 
            this.PlaylistsListBox.BackColor = System.Drawing.SystemColors.WindowFrame;
            this.PlaylistsListBox.Font = new System.Drawing.Font("Comic Sans MS", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PlaylistsListBox.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(136)))), ((int)(((byte)(0)))));
            this.PlaylistsListBox.FormattingEnabled = true;
            this.PlaylistsListBox.ItemHeight = 28;
            this.PlaylistsListBox.Location = new System.Drawing.Point(67, -3);
            this.PlaylistsListBox.Name = "PlaylistsListBox";
            this.PlaylistsListBox.Size = new System.Drawing.Size(321, 284);
            this.PlaylistsListBox.TabIndex = 0;
            this.PlaylistsListBox.DoubleClick += new System.EventHandler(this.PlaylistsListBox_DoubleClick);
            // 
            // SongsListBox
            // 
            this.SongsListBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.SongsListBox.Font = new System.Drawing.Font("Comic Sans MS", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SongsListBox.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(136)))), ((int)(((byte)(0)))));
            this.SongsListBox.FormattingEnabled = true;
            this.SongsListBox.ItemHeight = 28;
            this.SongsListBox.Location = new System.Drawing.Point(387, -3);
            this.SongsListBox.Name = "SongsListBox";
            this.SongsListBox.Size = new System.Drawing.Size(448, 284);
            this.SongsListBox.TabIndex = 1;
            this.SongsListBox.DoubleClick += new System.EventHandler(this.PlayButton_Click);
            // 
            // PlayButton
            // 
            this.PlayButton.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("PlayButton.BackgroundImage")));
            this.PlayButton.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.PlayButton.Location = new System.Drawing.Point(286, 49);
            this.PlayButton.Name = "PlayButton";
            this.PlayButton.Size = new System.Drawing.Size(69, 70);
            this.PlayButton.TabIndex = 2;
            this.PlayButton.UseVisualStyleBackColor = true;
            this.PlayButton.Click += new System.EventHandler(this.PlayButton_Click);
            // 
            // PauseButton
            // 
            this.PauseButton.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("PauseButton.BackgroundImage")));
            this.PauseButton.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.PauseButton.Location = new System.Drawing.Point(361, 49);
            this.PauseButton.Name = "PauseButton";
            this.PauseButton.Size = new System.Drawing.Size(60, 70);
            this.PauseButton.TabIndex = 3;
            this.PauseButton.UseVisualStyleBackColor = true;
            this.PauseButton.Click += new System.EventHandler(this.PauseButton_Click);
            // 
            // SongTrackBar
            // 
            this.SongTrackBar.Location = new System.Drawing.Point(92, 11);
            this.SongTrackBar.Maximum = 100;
            this.SongTrackBar.Name = "SongTrackBar";
            this.SongTrackBar.Size = new System.Drawing.Size(552, 69);
            this.SongTrackBar.TabIndex = 4;
            this.SongTrackBar.TickStyle = System.Windows.Forms.TickStyle.None;
            this.SongTrackBar.Scroll += new System.EventHandler(this.SongTrackBar_Scroll);
            // 
            // VolumeTrackBar
            // 
            this.VolumeTrackBar.Location = new System.Drawing.Point(607, 67);
            this.VolumeTrackBar.Maximum = 100;
            this.VolumeTrackBar.Name = "VolumeTrackBar";
            this.VolumeTrackBar.Size = new System.Drawing.Size(114, 69);
            this.VolumeTrackBar.TabIndex = 5;
            this.VolumeTrackBar.TickStyle = System.Windows.Forms.TickStyle.None;
            this.VolumeTrackBar.Value = 100;
            this.VolumeTrackBar.Scroll += new System.EventHandler(this.VolumeTrackBar_Scroll);
            // 
            // openFileDialog
            // 
            this.openFileDialog.FileName = "openFileDialog1";
            this.openFileDialog.Multiselect = true;
            this.openFileDialog.Title = "Check it out";
            this.openFileDialog.FileOk += new System.ComponentModel.CancelEventHandler(this.openFileDialog_FileOk);
            // 
            // timer
            // 
            this.timer.Interval = 1000;
            this.timer.Tick += new System.EventHandler(this.timer_Tick);
            // 
            // CurrentTimeLabel
            // 
            this.CurrentTimeLabel.AutoSize = true;
            this.CurrentTimeLabel.Location = new System.Drawing.Point(15, 27);
            this.CurrentTimeLabel.Name = "CurrentTimeLabel";
            this.CurrentTimeLabel.Size = new System.Drawing.Size(71, 20);
            this.CurrentTimeLabel.TabIndex = 6;
            this.CurrentTimeLabel.Text = "00:00:00";
            // 
            // EntireTimeLabel
            // 
            this.EntireTimeLabel.AutoSize = true;
            this.EntireTimeLabel.Location = new System.Drawing.Point(650, 27);
            this.EntireTimeLabel.Name = "EntireTimeLabel";
            this.EntireTimeLabel.Size = new System.Drawing.Size(71, 20);
            this.EntireTimeLabel.TabIndex = 7;
            this.EntireTimeLabel.Text = "00:00:00";
            // 
            // AddPlaylistButton
            // 
            this.AddPlaylistButton.BackColor = System.Drawing.Color.Silver;
            this.AddPlaylistButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.AddPlaylistButton.Location = new System.Drawing.Point(-8, -3);
            this.AddPlaylistButton.Name = "AddPlaylistButton";
            this.AddPlaylistButton.Size = new System.Drawing.Size(83, 123);
            this.AddPlaylistButton.TabIndex = 8;
            this.AddPlaylistButton.Text = "Add new Playlist";
            this.AddPlaylistButton.UseVisualStyleBackColor = false;
            this.AddPlaylistButton.Click += new System.EventHandler(this.AddPlaylistButton_Click);
            // 
            // AddSongButton
            // 
            this.AddSongButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(63)))), ((int)(((byte)(63)))), ((int)(((byte)(63)))));
            this.AddSongButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.AddSongButton.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.AddSongButton.Location = new System.Drawing.Point(387, 243);
            this.AddSongButton.Name = "AddSongButton";
            this.AddSongButton.Size = new System.Drawing.Size(446, 38);
            this.AddSongButton.TabIndex = 9;
            this.AddSongButton.Text = "Add new songs";
            this.AddSongButton.UseVisualStyleBackColor = false;
            this.AddSongButton.Visible = false;
            this.AddSongButton.Click += new System.EventHandler(this.AddSongButton_Click);
            // 
            // PlayNextButton
            // 
            this.PlayNextButton.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("PlayNextButton.BackgroundImage")));
            this.PlayNextButton.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.PlayNextButton.Location = new System.Drawing.Point(437, 49);
            this.PlayNextButton.Name = "PlayNextButton";
            this.PlayNextButton.Size = new System.Drawing.Size(68, 70);
            this.PlayNextButton.TabIndex = 10;
            this.PlayNextButton.UseVisualStyleBackColor = true;
            this.PlayNextButton.Click += new System.EventHandler(this.PlayNextButton_Click);
            // 
            // PlayPrevButton
            // 
            this.PlayPrevButton.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("PlayPrevButton.BackgroundImage")));
            this.PlayPrevButton.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.PlayPrevButton.Location = new System.Drawing.Point(201, 49);
            this.PlayPrevButton.Name = "PlayPrevButton";
            this.PlayPrevButton.Size = new System.Drawing.Size(69, 70);
            this.PlayPrevButton.TabIndex = 11;
            this.PlayPrevButton.UseVisualStyleBackColor = true;
            this.PlayPrevButton.Click += new System.EventHandler(this.PlayPrevButton_Click);
            // 
            // VolumeButton
            // 
            this.VolumeButton.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("VolumeButton.BackgroundImage")));
            this.VolumeButton.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.VolumeButton.Location = new System.Drawing.Point(552, 61);
            this.VolumeButton.Name = "VolumeButton";
            this.VolumeButton.Size = new System.Drawing.Size(58, 58);
            this.VolumeButton.TabIndex = 12;
            this.VolumeButton.UseVisualStyleBackColor = true;
            this.VolumeButton.Click += new System.EventHandler(this.VolumeButton_Click);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(136)))), ((int)(((byte)(0)))));
            this.panel1.Controls.Add(this.AddPlaylistButton);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Left;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(67, 447);
            this.panel1.TabIndex = 13;
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.Silver;
            this.panel2.Controls.Add(this.PlayNextButton);
            this.panel2.Controls.Add(this.PlayPrevButton);
            this.panel2.Controls.Add(this.VolumeButton);
            this.panel2.Controls.Add(this.EntireTimeLabel);
            this.panel2.Controls.Add(this.PlayButton);
            this.panel2.Controls.Add(this.VolumeTrackBar);
            this.panel2.Controls.Add(this.CurrentTimeLabel);
            this.panel2.Controls.Add(this.PauseButton);
            this.panel2.Controls.Add(this.SongTrackBar);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel2.Location = new System.Drawing.Point(67, 279);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(769, 168);
            this.panel2.TabIndex = 14;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(836, 447);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.AddSongButton);
            this.Controls.Add(this.SongsListBox);
            this.Controls.Add(this.PlaylistsListBox);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AudioPlayer";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.MainForm_FormClosed);
            ((System.ComponentModel.ISupportInitialize)(this.SongTrackBar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.VolumeTrackBar)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox PlaylistsListBox;
        private System.Windows.Forms.ListBox SongsListBox;
        private System.Windows.Forms.Button PlayButton;
        private System.Windows.Forms.Button PauseButton;
        private System.Windows.Forms.TrackBar SongTrackBar;
        private System.Windows.Forms.TrackBar VolumeTrackBar;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.Timer timer;
        private System.Windows.Forms.Label CurrentTimeLabel;
        private System.Windows.Forms.Label EntireTimeLabel;
        private System.Windows.Forms.Button AddPlaylistButton;
        private System.Windows.Forms.Button AddSongButton;
        private System.Windows.Forms.Button PlayNextButton;
        private System.Windows.Forms.Button PlayPrevButton;
        private System.Windows.Forms.Button VolumeButton;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
    }
}

