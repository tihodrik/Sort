using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace Traversals
{
    public partial class Creation : Form
    {
        public Dictionary<int, Dictionary<int, int>> AdjacencyList;
        public Creation()
        {
            NativeMethods.AllocConsole();
            Console.ForegroundColor = ConsoleColor.Red;

            InitializeComponent();

        }
        private void HighightLine(string line, int pos, Color color)
        {           
            content.SelectionStart = pos;
            content.SelectionLength = line.Length;
            content.SelectionColor = color;
        }
        private void create_Click(object sender, EventArgs e)
        {
            Regex input = new Regex(@"^(\d)+\s(\d)+\s(\d)+$");
            int pos = 0;

            HighightLine(content.Text, 0, Color.Black);
            bool correct = true;


            foreach (var line in content.Lines)
            {
                if (!input.IsMatch(line))
                {
                    HighightLine(line, pos, Color.Red);
                    correct = false;
                }
                pos += line.Length + 1; // +1 на символ переноса строки
            }

            if (!correct)
            {
                return;
            }

            // Если ввод осуществлен коррекно - создаем списки смежности

            AdjacencyList = new Dictionary<int, Dictionary<int, int>>();

            string[] tmp;
            foreach (var line in content.Lines)
            {
                tmp = line.Split(' ');
                int key1 = int.Parse(tmp[0]);
                int key2 = int.Parse(tmp[1]);
                int value = int.Parse(tmp[2]);

                if (!AdjacencyList.ContainsKey(key1)) {
                    AdjacencyList.Add(key1, new Dictionary<int, int>());
                }

                if (!AdjacencyList[key1].ContainsKey(key2))
                {

                    AdjacencyList[key1].Add(key2, value);
                }
                else {
                    Console.WriteLine("Impossible to add one more path from " + key1 + " to " + key2 + " (weight: " + value + ")");
                }   
            }

            // Диалог обходов
            Traversal traversal = new Traversal();
            traversal.ShowDialog(this);
        }
    }
}
