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
    public partial class Delete : Form
    {
        List<int>[] hash;
        public Delete(List<int>[] hashtable)
        {
            hash = hashtable;
            InitializeComponent();
            CenterToScreen();
            this.KeyPreview = true;
            this.KeyDown += EnterClick;
        }

        private void del_Click(object sender, EventArgs e)
        {
            Add ownerAdd = this.Owner as Add;

            int pattern = int.Parse(number.Text);
            int m = hash.Count();
            bool removed = false;

            if ((ownerAdd.Controls["hashTYPE"].Controls["openHASH"] as RadioButton).Checked)
            {
                for (int i = 0; i < hash[pattern % m].Count; i++)
                {
                    if (hash[pattern % m][i] == pattern)
                    {
                        hash[pattern % m].RemoveAt(i);
                        result.Text = "Element " + pattern + " removed";
                        removed = true;
                    }
                }
            }
            else
            {
                int step = ownerAdd.step;
                int index = pattern % m;

                for (int i = 0; i < m && !removed; i++)
                {
                    for (int j = 1;( (index + i + j * step) % m != (index + i) % m ) && !removed; j++)
                    {
                        if (hash[(index + i + j * step) % m].Count > 0)
                        {        
                            if (hash[(index + i + j * step) % m][0] == pattern)
                            {
                                hash[(index + i + j * step) % m].RemoveAt(0);
                                result.Text = "Element " + pattern + " removed";
                                removed = true;
                            }
                        }
                    }
                }
            }
            if (removed)
            {
                ownerAdd.hash = hash;
                ownerAdd.free--;
                ownerAdd.RefreshAdd();
                return;
            }

            result.Text = "There is no element " + pattern + " in the hash-table";
            return;

        }
        private void EnterClick(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                del_Click(sender, e);
            }
        }
    }
}
