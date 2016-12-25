using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Hash
{
    public partial class Search : Form
    {
        private List<int>[] hash;
        public Search(List<int>[] hashtable)
        {
            hash = hashtable;
            InitializeComponent();
            CenterToScreen();
            this.KeyPreview = true;

            this.KeyDown += EnterClick;
        }

        private void search_Click(object sender, EventArgs e)
        {
            int pattern;
            if (!int.TryParse(number.Text, out pattern))
            {
                return;
            }

            int m = hash.Count();
            Add ownerAdd = this.Owner as Add;

            if ((ownerAdd.Controls["hashTYPE"].Controls["openHASH"] as RadioButton).Checked)
            {
                foreach (var element in hash[pattern % m])
                {
                    if (element == pattern)
                    {
                        result.Text = "Element " + pattern + " has been found!";
                        return;
                    }
                }
                result.Text = "There is no element " + pattern + " in the hash-table";
                return;
            }
            else
            {
                int step = ownerAdd.step;
                int index = pattern % m;
                if (hash[index][0] == pattern)
                {
                    result.Text = "Element " + pattern + " has been found!";
                    return;
                }

                for (int i = 0; i < m; i++)
                {
                    for (int j = 1; (index + i + j * step) % m != (index + i) % m; j++)
                    {
                        if (hash[(index + i + j * step) % m].Count > 0)
                        {
                            if (hash[(index + i + j * step) % m][0] == pattern)
                            {

                                result.Text = "Element " + pattern + " has been found!";
                                return;
                            }
                        }
                        else
                        {
                            result.Text = "There is no element " + pattern + " in the hash-table";
                            return;
                        }
                    }
                }
                result.Text = "There is no element " + pattern + " in the hash-table";
                return;
            }
        }
        private void EnterClick(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                search_Click(sender, e);
            }
        }
    }
}
