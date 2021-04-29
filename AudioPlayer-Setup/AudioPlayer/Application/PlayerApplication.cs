using System;
using Un4seen.Bass;

namespace AudioPlayer
{
    public static class PlayerApplication
    {
        /// <summary>
        /// Частота
        /// </summary>
        public const int HZ = 44100;
        /// <summary>
        /// Состояние инициализации
        /// </summary>
        private static bool InitDefaultDevice { get; set; }
        /// <summary>
        /// Канал
        /// </summary>
        public static int Stream { get; set; }
        /// <summary>
        /// Громкость
        /// </summary>
        public static int Volume = 100;
        /// <summary>
        /// Остановлена ли песня
        /// </summary>
        private static bool isStopped = true;
        /// <summary>
        /// Инициализация Bass.dll
        /// </summary>
        /// <param name="hz"></param>
        /// <returns></returns>
        public static bool InitBass(int hz)
        {
            if (!InitDefaultDevice)
            {
                InitDefaultDevice = Bass.BASS_Init(-1, hz, BASSInit.BASS_DEVICE_DEFAULT, IntPtr.Zero);
            }
            return InitDefaultDevice;
        }
        /// <summary>
        /// Инициализация плагинов для просушивания всех форматов
        /// </summary>
        public static void InitPlugins()
        {
            string path = PlayerInfrastructure.PluginsPath;
            Bass.BASS_PluginLoad(path + @"Plugins\bassalac.dll");
            Bass.BASS_PluginLoad(path + @"Plugins\basscd.dll");
            Bass.BASS_PluginLoad(path + @"Plugins\bassdsd.dll");
            Bass.BASS_PluginLoad(path + @"Plugins\bassflac.dll");
            Bass.BASS_PluginLoad(path + @"Plugins\basshls.dll");
            Bass.BASS_PluginLoad(path + @"Plugins\bassmidi.dll");
            Bass.BASS_PluginLoad(path + @"Plugins\basswebm.dll");
            Bass.BASS_PluginLoad(path + @"Plugins\basswma.dll");
            Bass.BASS_PluginLoad(path + @"Plugins\basswv.dll");
            Bass.BASS_PluginLoad(path + @"\Plugins\bassopus.dll");
        }
        /// <summary>
        /// PLay
        /// </summary>
        /// <param name="filename"></param>
        /// <param name="vol"></param>
        public static void Play(string filename, int vol)
        {
            if (Bass.BASS_ChannelIsActive(Stream) == BASSActive.BASS_ACTIVE_PAUSED)
            {
                Bass.BASS_ChannelPlay(Stream, false);
                return;
            }
            Stop();
            if (InitBass(HZ))
            {
                Stream = Bass.BASS_StreamCreateFile(filename, 0, 0, BASSFlag.BASS_DEFAULT);
                if (Stream != 0)
                {
                    Volume = vol;
                    Bass.BASS_ChannelSetAttribute(Stream, BASSAttribute.BASS_ATTRIB_VOL, Volume / 100F);
                    Bass.BASS_ChannelPlay(Stream, false);
                }
            }
            isStopped = false;
        }
        /// <summary>
        /// Stop
        /// </summary>
        public static void Stop()
        {
            Bass.BASS_ChannelStop(Stream);
            Bass.BASS_StreamFree(Stream);
            isStopped = true;
        }
        /// <summary>
        /// Получить время потока в секундах
        /// </summary>
        /// <param name="stream"></param>
        /// <returns></returns>
        public static int GetTimeOfStream(int stream)
        {
            long TimeBytes = Bass.BASS_ChannelGetLength(stream);
            int Time = (int)Bass.BASS_ChannelBytes2Seconds(stream, TimeBytes);
            return Time;
        }
        /// <summary>
        /// Получить текущую позицию потока в секундах
        /// </summary>
        /// <param name="stream"></param>
        /// <returns></returns>
        public static int GetPosOfStream(int stream)
        {
            long pos = Bass.BASS_ChannelGetPosition(stream);
            int posSec = (int)Bass.BASS_ChannelBytes2Seconds(stream, pos);
            return posSec;
        }
        /// <summary>
        /// Установить позицию потока
        /// </summary>
        /// <param name="stream"></param>
        /// <param name="pos"></param>
        public static void SetPosOfStream(int stream, int pos)
        {
            Bass.BASS_ChannelSetPosition(stream, (double)pos);
        }
        /// <summary>
        /// Установить звук потока
        /// </summary>
        /// <param name="stream"></param>
        /// <param name="vol"></param>
        public static void SetVolumeToStream(int stream, int vol)
        {
            Volume = vol;
            Bass.BASS_ChannelSetAttribute(stream, BASSAttribute.BASS_ATTRIB_VOL, Volume / 100F);
        }
        /// <summary>
        /// Пауза
        /// </summary>
        public static void Pause()
        {
            if (Bass.BASS_ChannelIsActive(Stream) == BASSActive.BASS_ACTIVE_PLAYING)
            {
                Bass.BASS_ChannelPause(Stream);
            }
            else if (Bass.BASS_ChannelIsActive(Stream) == BASSActive.BASS_ACTIVE_PAUSED)
            {
                Bass.BASS_ChannelPlay(Stream, false);
            }
        }
        /// <summary>
        /// Следующий трек
        /// </summary>
        /// <returns></returns>
        public static bool ToNextTrack(Playlist playlist)
        {
            if (!isStopped && Bass.BASS_ChannelIsActive(Stream) == BASSActive.BASS_ACTIVE_STOPPED)
            {
                PlayLists.CurrentTrackNumber = (PlayLists.CurrentTrackNumber + 1) % playlist.Count;
                Play(playlist[PlayLists.CurrentTrackNumber], Volume);
                return true;
            }
            return false;
        }
        /// <summary>
        /// Играть следующий
        /// </summary>
        /// <param name="playlist"></param>
        public static void PlayNext(Playlist playlist)
        {
            PlayLists.CurrentTrackNumber = (PlayLists.CurrentTrackNumber + 1) % playlist.Count;
            Play(playlist[PlayLists.CurrentTrackNumber], Volume);
        }
        /// <summary>
        /// Играть предыдущий
        /// </summary>
        /// <param name="playlist"></param>
        public static void PlayPrev(Playlist playlist)
        {
            PlayLists.CurrentTrackNumber = (PlayLists.CurrentTrackNumber + playlist.Count - 1) % playlist.Count;
            Play(playlist[PlayLists.CurrentTrackNumber], Volume);
        }
        /// <summary>
        /// Запись плейлистов в файл на закрытие формы
        /// </summary>
        public static void WriteLog()
        {
            using (System.IO.StreamWriter sc = new System.IO.StreamWriter("Playlists.log"))
            {
                for (int i = 0; i < PlayLists.Playlists.Count; i++)
                {
                    sc.WriteLine("\"" + PlayLists.Playlists[i].Name + "\"");
                    for (int j = 0; j < PlayLists.Playlists[i].Count; j++)
                    {
                        sc.WriteLine(PlayLists.Playlists[i][j]);
                    }
                }
            }
        }
    }
}
