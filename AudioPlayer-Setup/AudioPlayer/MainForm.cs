using System;
using System.ComponentModel;
using System.Windows.Forms;

namespace AudioPlayer
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
            openFileDialog.Filter = PlayerInfrastructure.Filters;
            PlayerApplication.InitBass(PlayerApplication.HZ);
            PlayerApplication.InitPlugins();
            ReadLog();
            if (PlayLists.Playlists.Count > 0) AddSongButton.Visible = true;
        }

        private void PlayButton_Click(object sender, EventArgs e)
        {
            if (SongsListBox.SelectedIndex == -1) return;
            string current = PlayLists.Playlists[PlaylistsListBox.SelectedIndex][SongsListBox.SelectedIndex];
            PlayLists.CurrentTrackNumber = SongsListBox.SelectedIndex;
            PlayerApplication.Play(current, PlayerApplication.Volume);
            CurrentTimeLabel.Text = TimeSpan.FromSeconds(PlayerApplication.GetPosOfStream(PlayerApplication.Stream)).ToString();
            EntireTimeLabel.Text = TimeSpan.FromSeconds(PlayerApplication.GetTimeOfStream(PlayerApplication.Stream)).ToString();
            SongTrackBar.Maximum = PlayerApplication.GetTimeOfStream(PlayerApplication.Stream);
            SongTrackBar.Value = PlayerApplication.GetPosOfStream(PlayerApplication.Stream);
            timer.Enabled = true;
        }

        private void AddPlaylistButton_Click(object sender, EventArgs e)
        {
            var form = new NamePlayListForm();
            form.ShowDialog();
            if (!String.IsNullOrWhiteSpace(form.name))
            {
                PlaylistsListBox.Items.Add(form.name);
                PlayLists.Playlists.Add(new Playlist(form.name));
                AddSongButton.Visible = true;
                PlaylistsListBox.SelectedIndex = PlaylistsListBox.Items.Count - 1;
            }
            PlaylistsListBox_DoubleClick(sender, e);
        }

        private void AddSongButton_Click(object sender, EventArgs e)
        {
            if ((PlaylistsListBox.Items.Count != 0) && (PlaylistsListBox.SelectedIndex != -1))
            {
                openFileDialog.ShowDialog();
            }
        }

        private void openFileDialog_FileOk(object sender, CancelEventArgs e)
        {
            string[] songs = openFileDialog.FileNames;
            for (int i = 0; i < songs.Length; i++)
            {
                SongsListBox.Items.Add(PlayerInfrastructure.GetFileName(songs[i]));
                PlayLists.Playlists[PlaylistsListBox.SelectedIndex].Add(songs[i]);
            }
        }

        private void PlaylistsListBox_DoubleClick(object sender, EventArgs e)
        {
            if (PlaylistsListBox.Items.Count <= 0)
                return;
            SongsListBox.Items.Clear();
            for (int i = 0; i < PlayLists.Playlists[PlaylistsListBox.SelectedIndex].Count; i++)
            {
                SongsListBox.Items.Add(PlayerInfrastructure.GetFileName(PlayLists.Playlists[PlaylistsListBox.SelectedIndex][i]));
            }
        }

        private void PauseButton_Click(object sender, EventArgs e)
        {
            PlayerApplication.Pause();
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            CurrentTimeLabel.Text = TimeSpan.FromSeconds(PlayerApplication.GetPosOfStream(PlayerApplication.Stream)).ToString();
            SongTrackBar.Value = PlayerApplication.GetPosOfStream(PlayerApplication.Stream);

            if (PlayerApplication.ToNextTrack(PlayLists.Playlists[PlaylistsListBox.SelectedIndex]))
            {
                SongsListBox.SelectedIndex = PlayLists.CurrentTrackNumber;
                CurrentTimeLabel.Text = TimeSpan.FromSeconds(PlayerApplication.GetPosOfStream(PlayerApplication.Stream)).ToString();
                EntireTimeLabel.Text = TimeSpan.FromSeconds(PlayerApplication.GetTimeOfStream(PlayerApplication.Stream)).ToString();
                SongTrackBar.Maximum = PlayerApplication.GetTimeOfStream(PlayerApplication.Stream);
                SongTrackBar.Value = PlayerApplication.GetPosOfStream(PlayerApplication.Stream);
            }
        }

        private void SongTrackBar_Scroll(object sender, EventArgs e)
        {
            PauseButton_Click(sender, e);
            PlayerApplication.SetPosOfStream(PlayerApplication.Stream, SongTrackBar.Value);
            PauseButton_Click(sender, e);
        }

        private void VolumeTrackBar_Scroll(object sender, EventArgs e)
        {
            PlayerApplication.SetVolumeToStream(PlayerApplication.Stream, VolumeTrackBar.Value);
        }

        private void PlayNextButton_Click(object sender, EventArgs e)
        {
            PlayerApplication.PlayNext(PlayLists.Playlists[PlaylistsListBox.SelectedIndex]);
            SongsListBox.SelectedIndex = PlayLists.CurrentTrackNumber;
            EntireTimeLabel.Text = TimeSpan.FromSeconds(PlayerApplication.GetTimeOfStream(PlayerApplication.Stream)).ToString();
        }

        private void PlayPrevButton_Click(object sender, EventArgs e)
        {
            PlayerApplication.PlayPrev(PlayLists.Playlists[PlaylistsListBox.SelectedIndex]);
            SongsListBox.SelectedIndex = PlayLists.CurrentTrackNumber;
            EntireTimeLabel.Text = TimeSpan.FromSeconds(PlayerApplication.GetTimeOfStream(PlayerApplication.Stream)).ToString();
        }

        private void VolumeButton_Click(object sender, EventArgs e)
        {
            if (VolumeTrackBar.Enabled)
            {
                PlayerApplication.SetVolumeToStream(PlayerApplication.Stream, 0);
                VolumeTrackBar.Enabled = false;
            }
            else
            {
                PlayerApplication.SetVolumeToStream(PlayerApplication.Stream, VolumeTrackBar.Value);
                VolumeTrackBar.Enabled = true;
            }
        }

        private void MainForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            PlayerApplication.WriteLog();
        }

        private void ReadLog()
        {
            try
            {
                using (var sr = new System.IO.StreamReader("Playlists.log"))
                {
                    string line;
                    while ((line = sr.ReadLine()) != null)
                    {
                        if (line[0] == '"' && line[line.Length - 1] == '"')
                        {
                            line = line.Trim('"');
                            PlaylistsListBox.Items.Add(line);
                            PlayLists.Playlists.Add(new Playlist(line));
                            PlaylistsListBox.SelectedIndex = PlaylistsListBox.Items.Count - 1;
                        }
                        else
                        {
                            if (System.IO.File.Exists(line) && !PlayLists.Playlists[PlaylistsListBox.SelectedIndex].Contains(line))
                                PlayLists.Playlists[PlaylistsListBox.SelectedIndex].Add(line);
                        }
                    }
                }
                PlaylistsListBox_DoubleClick(new object(), new EventArgs());
            }
            catch (Exception ex) { }
        }
    }
}
