using System.Collections.Generic;

namespace AudioPlayer
{
    public class Playlist
    {
        public List<string> list { get; set; }

        public int Count { get { return list.Count; } }

        public string Name { get; set; }

        public Playlist()
        {
            list = new List<string>();
        }

        public Playlist(string name):this()
        {
            Name = name;
        }

        public bool Contains(string item)
        {
            return list.Contains(item);
        }

        public string this[int x]
        {
            get
            {
                return list[x];
            }
            set
            {
                list[x] = value;
            }
        }

        public void Add(string song)
        {
            list.Add(song);
        }
    }
}
