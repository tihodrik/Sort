using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Traversals
{
    public partial class Traversal : Form
    {
        Dictionary<int, bool> visited;
        List<int> keys;
        Creation owner;

        public Traversal()
        {
            InitializeComponent();
        }

        public void DepthTraversal()
        {
            owner = this.Owner as Creation;
            keys = owner.AdjacencyList.Keys.ToList();
            visited = new Dictionary<int, bool>();

            foreach (var key1 in keys)
            {
                if (!visited.ContainsKey(key1)) {
                    visited.Add(key1, false);
                }
                foreach (var key2 in owner.AdjacencyList[key1].Keys)
                {
                    if (!visited.ContainsKey(key2))
                    {
                        visited.Add(key2, false);
                    }
                }
            }
            Stack<int> S = new Stack<int>();
            result.Clear();

            int first = visited.Keys.First();
            S.Push(first);

            visited[first] = true;
            result.AppendText("Visited: " + first.ToString() + "\n");

            while (S.Count > 0)
            {
                int begin = S.First();
                bool allVisited = true;
                if (owner.AdjacencyList.ContainsKey(begin))
                {
                    foreach (var end in owner.AdjacencyList[begin].Keys)
                    {
                        if (!visited[end])
                        {
                            result.AppendText("(" + begin.ToString() + " - " + end.ToString() + ", weight: " + (owner.AdjacencyList[begin][end]) + ")\n");
                            S.Push(end);

                            visited[end] = true;
                            result.AppendText("Visited: " + end.ToString() + "\n");

                            allVisited = false;
                            break;
                        }
                    }
                }
                if (allVisited)
                {
                    S.Pop();
                }
            }

        }
        public void BreadthTraversal()
        {
            owner = this.Owner as Creation;
            keys = owner.AdjacencyList.Keys.ToList();
            visited = new Dictionary<int, bool>();

            foreach (var key1 in keys)
            {
                if (!visited.ContainsKey(key1))
                {
                    visited.Add(key1, false);
                }
                foreach (var key2 in owner.AdjacencyList[key1].Keys)
                {
                    if (!visited.ContainsKey(key2))
                    {
                        visited.Add(key2, false);
                    }
                }
            }
            Queue<int> Q = new Queue<int>();
            result.Clear();

            int first = visited.Keys.First();
            Q.Enqueue(first);

            visited[first] = true;
            result.AppendText("Visited: " + first.ToString() + "\n");

            while (Q.Count > 0)
            {
                int begin = Q.First();
                bool allVisited = true;
                if (owner.AdjacencyList.ContainsKey(begin))
                {
                    foreach (var end in owner.AdjacencyList[begin].Keys)
                    {
                        if (!visited[end])
                        {
                            result.AppendText("(" + begin.ToString() + " - " + end.ToString() + ", weight: " + (owner.AdjacencyList[begin][end]) + ")\n");
                            Q.Enqueue(end);

                            visited[end] = true;
                            result.AppendText("Visited: " + end.ToString() + "\n");

                            allVisited = false;
                            break;
                        }
                    }
                }
                if (allVisited)
                {
                    Q.Dequeue();
                }
            }
        }

        private void traverse_Click(object sender, EventArgs e)
        {
            owner = this.Owner as Creation;

            if ((this.Controls["type"].Controls["depth"] as RadioButton).Checked)
            {
                DepthTraversal();
            }
            else
            {
                BreadthTraversal();
            }
        }
    }
}
