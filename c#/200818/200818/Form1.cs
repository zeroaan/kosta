using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _200818
{
    public partial class Form1 : Form
    {
        string ConnectionStr;
        int n1=0, n2=0, n3=0, n4=0, n5=0;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string str = textBox1.Text;
            if (checkBox1.Checked)
            {
                textBox2.Text = str.ToLower();
            }
            else
            {
                textBox2.Text = str.ToUpper();
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            int sel = comboBox1.SelectedIndex;
            string str = "Hi, my name is ";
            if (sel == 0) textBox1.Text = str + comboBox1.SelectedItem;
            else if (sel == 1) textBox1.Text = str + comboBox1.SelectedItem;
            else if (sel == 2) textBox1.Text = str + comboBox1.SelectedItem;
            else if (sel == 3) textBox1.Text = str + comboBox1.SelectedItem;
            else textBox1.Text = str + comboBox1.SelectedItem;
        }

        private void testToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            PortSet dlg = new PortSet();
            dlg.n1 = n1;
            dlg.n2 = n2;
            dlg.n3 = n3;
            dlg.n4 = n4;
            dlg.n5 = n5;
            dlg.ShowDialog();
            ConnectionStr = dlg.ConnectionStr;
            n1 = dlg.n1;
            n2 = dlg.n2;
            n3 = dlg.n3;
            n4 = dlg.n4;
            n5 = dlg.n5;
            textBox3.Text = ConnectionStr;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Text = "TEST";
        }
    }
}