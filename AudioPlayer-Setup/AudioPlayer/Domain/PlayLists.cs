using System.Collections.Generic;

namespace AudioPlayer
{
    public class PlayLists
    {
        /// <summary>
        /// Список плейлистов
        /// </summary>
        public static List<Playlist> Playlists { get; set; }
        /// <summary>
        /// Номер текущего трека
        /// </summary>
        public static int CurrentTrackNumber { get; set; }

        static PlayLists()
        {
            Playlists = new List<Playlist>();
        }
    }
}
