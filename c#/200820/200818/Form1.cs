using Microsoft.SqlServer.Server;
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
using System.Xml;

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
        string s1, s2, s3, s4, s5;

        string RecvBuf;

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

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            if(textBox3.TextLength < 5)
            {
                label6.Text = "아이디는 5자리 이상";
            }
            else if(textBox3.TextLength > 10)
            {
                label6.Text = "아이디는 10자리 이하";
            }
            else
            {
                label6.Text = "";
            }
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            if (textBox4.TextLength < 8)
            {
                label7.Text = "비밀번호는 8자리 이상";
            }
            else if (textBox4.TextLength > 16)
            {
                label7.Text = "비밀번호는 16자리 이하";
            }
            else
            {
                label7.Text = "";
            }
        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            RecvBuf += serialPort1.ReadExisting();
                
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            textBox2.Text = RecvBuf;
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            if (textBox5.Text != textBox4.Text)
            {
                label8.Text = "입력한 PW가 같지 않습니다.";
            }
            else
            {
                label8.Text = "";
            }
        }


        private void textBox1_KeyPress_1(object sender, KeyPressEventArgs e)
        {
            // textBox2.Text += "" + e.KeyChar;
            char c = e.KeyChar;
            if(serialPort1.IsOpen == true)
            {
                serialPort1.Write("" + c);
            }
        }

        private void portOpenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen == true)
            {
                serialPort1.Close();
            }
            serialPort1.PortName = s1;
            serialPort1.BaudRate = Int32.Parse(s2);
            serialPort1.Parity = (System.IO.Ports.Parity)n3;
            serialPort1.DataBits = Int32.Parse(s4);
            serialPort1.StopBits = (System.IO.Ports.StopBits)n5 + 1;
            serialPort1.Open();
            if (serialPort1.IsOpen == true)
            {
                toolStripStatusLabel1.BackColor = Color.Green;
            }
            else toolStripStatusLabel1.BackColor = Color.Red;
        }

        private void portCloseToolStripMenuItem_Click(object sender, EventArgs e)
        {
            serialPort1.Close();
            toolStripStatusLabel1.BackColor = Color.Red;
        }

        private void portSetupToolStripMenuItem_Click(object sender, EventArgs e)
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
            s1 = dlg.cbPortno.Text;
            s2 = dlg.cbBaudrate.Text;
            s3 = dlg.cbParity.Text;
            s4 = dlg.cbDatabits.Text;
            s5 = dlg.cbStopbit.Text;
            toolStripStatusLabel1.Text = ConnectionStr;
            textBox1.Text = ConnectionStr;

            portOpenToolStripMenuItem_Click(sender, e);
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
            else textBox1.Text = string.Format("you select {0, 5} item.", sel);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Text = "TEST";
        }
    }
}