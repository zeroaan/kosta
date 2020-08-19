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
    public partial class PortSet : Form
    {
        public string ConnectionStr;
        public int n1, n2, n3, n4, n5;

        public PortSet()
        {
            InitializeComponent();
         
            cbPortno.SelectedIndex = n1;
            cbBaudrate.SelectedIndex = n2;
            cbParity.SelectedIndex = n3;
            cbDatabits.SelectedIndex = n4;
            cbStopbit.SelectedIndex = n5;
        }

        private void port_Click(object sender, EventArgs e)
        {
            ConnectionStr = cbPortno.Text + cbBaudrate.Text;

            n1 = cbPortno.SelectedIndex;
            n2 = cbBaudrate.SelectedIndex;
            n3 = cbParity.SelectedIndex;
            n4 = cbDatabits.SelectedIndex;
            n5 = cbStopbit.SelectedIndex;
        }
    }
}
