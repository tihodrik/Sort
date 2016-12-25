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
    public partial class RandomCOUNT : Form
    {
        public RandomCOUNT()
        {
            InitializeComponent();
            this.KeyPreview = true;
            this.KeyDown += EnterClick;
        }

        private void OK_Click(object sender, EventArgs e)
        {
            (this.Owner).Controls["content"].Text = count.Text;
            this.Close();

        }
        private void EnterClick(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                OK_Click(sender, e);
            }
        }
    }
}
