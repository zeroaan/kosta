using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;

namespace _200818
{
    public partial class Form1 : Form
    {   
        [DllImport("kernel32.dll")]
        private static extern int GetPrivateProfileString(string section,
            string key, string def, StringBuilder retVal, int size, string filePath);

        [DllImport("kernel32")]
        private static extern long WritePrivateProfileString(string section,
            string key, string val, string filePath);


        string ConnectionStr;
        string pn;
        int n1=0, n2=0, n3=0, n4=0, n5=0;
        public Form1()
        {
            InitializeComponent();

            StringBuilder tmp = new StringBuilder(); tmp.Capacity = 500;
            string str;
            GetPrivateProfileString("ComPort", "ComName", "0", tmp, tmp.Capacity, @"C:\\Temp\\a.ini"); 
            pn = tmp.ToString();
            n1 = Int32.Parse(pn);
            GetPrivateProfileString("ComPort", "BaudRate", "0", tmp, tmp.Capacity, @"C:\\Temp\\a.ini");
            str = tmp.ToString();
            n2 = Int32.Parse(str);
            GetPrivateProfileString("ComPort", "Parity", "0", tmp, tmp.Capacity, @"C:\\Temp\\a.ini");
            str = tmp.ToString();
            n3 = Int32.Parse(str);
            GetPrivateProfileString("ComPort", "DataBits", "0", tmp, tmp.Capacity, @"C:\\Temp\\a.ini");
            str = tmp.ToString();
            n4 = Int32.Parse(str);
            GetPrivateProfileString("ComPort", "StopBit", "0", tmp, tmp.Capacity, @"C:\\Temp\\a.ini");
            str = tmp.ToString();
            n5 = Int32.Parse(str);
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            WritePrivateProfileString("ComPort", "ComName", pn, @"C:\\Temp\\a.ini");
            WritePrivateProfileString("ComPort", "BaudRate", "0", @"C:\\Temp\\a.ini");
            WritePrivateProfileString("ComPort", "Parity", "0", @"C:\\Temp\\a.ini");
            WritePrivateProfileString("ComPort", "DataBits", "0", @"C:\\Temp\\a.ini");
            WritePrivateProfileString("ComPort", "StopBit", "0", @"C:\\Temp\\a.ini");
        }

        private void testToolStripMenuItem_Click(object sender, EventArgs e)
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
            toolStripStatusLabel1.Text = ConnectionStr;
            toolStripStatusLabel1.BackColor = Color.Green;
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

        private void button2_Click(object sender, EventArgs e)
        {
            this.Text = "TEST";
        }
    }
}