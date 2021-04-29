using System;

namespace AudioPlayer
{
    public static class PlayerInfrastructure
    {
        /// <summary>
        /// Фильтры форматов
        /// </summary>
        public static string Filters = "Все форматы|*.mp3;*.wav;*.m4a;*.mp4;*.tta;*.alac;*.ogg;*.opus;*.ac3;*.ape;*.mpc;*.flac;*.wma;*.wv";
        /// <summary>
        /// Путь к плагинам
        /// </summary>
        public static string PluginsPath;

        static PlayerInfrastructure()
        {
            string path = AppDomain.CurrentDomain.BaseDirectory;
            PluginsPath = path.Substring(0, path.LastIndexOf('\\'));
        }
        /// <summary>
        /// Получить название песни
        /// </summary>
        /// <param name="file"></param>
        /// <returns></returns>
        public static string GetFileName(string file)
        {
            string[] tmp = file.Split('\\');
            return tmp[tmp.Length - 1];
        }
    }
}
