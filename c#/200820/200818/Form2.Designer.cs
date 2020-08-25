namespace _200818
{
    partial class PortSet
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.cbBaudrate = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.cbParity = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.cbDatabits = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.cbStopbit = new System.Windows.Forms.ComboBox();
            this.port = new System.Windows.Forms.Button();
            this.cbPortno = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("굴림", 12F);
            this.label1.Location = new System.Drawing.Point(63, 45);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(80, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "Port No.";
            // 
            // cbBaudrate
            // 
            this.cbBaudrate.Font = new System.Drawing.Font("굴림", 12F);
            this.cbBaudrate.FormattingEnabled = true;
            this.cbBaudrate.Items.AddRange(new object[] {
            "9600",
            "12800",
            "25600",
            "54000",
            "115200"});
            this.cbBaudrate.Location = new System.Drawing.Point(149, 84);
            this.cbBaudrate.Name = "cbBaudrate";
            this.cbBaudrate.Size = new System.Drawing.Size(190, 28);
            this.cbBaudrate.TabIndex = 1;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("굴림", 12F);
            this.label3.Location = new System.Drawing.Point(88, 129);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(55, 20);
            this.label3.TabIndex = 0;
            this.label3.Text = "Parity";
            // 
            // cbParity
            // 
            this.cbParity.Font = new System.Drawing.Font("굴림", 12F);
            this.cbParity.FormattingEnabled = true;
            this.cbParity.Items.AddRange(new object[] {
            "None",
            "Odd",
            "Even",
            "Mark",
            "Space"});
            this.cbParity.Location = new System.Drawing.Point(149, 126);
            this.cbParity.Name = "cbParity";
            this.cbParity.Size = new System.Drawing.Size(190, 28);
            this.cbParity.TabIndex = 1;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("굴림", 12F);
            this.label4.Location = new System.Drawing.Point(57, 173);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(86, 20);
            this.label4.TabIndex = 0;
            this.label4.Text = "Data Bits";
            // 
            // cbDatabits
            // 
            this.cbDatabits.Font = new System.Drawing.Font("굴림", 12F);
            this.cbDatabits.FormattingEnabled = true;
            this.cbDatabits.Items.AddRange(new object[] {
            "7",
            "8"});
            this.cbDatabits.Location = new System.Drawing.Point(149, 170);
            this.cbDatabits.Name = "cbDatabits";
            this.cbDatabits.Size = new System.Drawing.Size(190, 28);
            this.cbDatabits.TabIndex = 1;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("굴림", 12F);
            this.label5.Location = new System.Drawing.Point(67, 218);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(76, 20);
            this.label5.TabIndex = 0;
            this.label5.Text = "Stop bit";
            // 
            // cbStopbit
            // 
            this.cbStopbit.Font = new System.Drawing.Font("굴림", 12F);
            this.cbStopbit.FormattingEnabled = true;
            this.cbStopbit.Items.AddRange(new object[] {
            "1",
            "2",
            "1.5"});
            this.cbStopbit.Location = new System.Drawing.Point(149, 215);
            this.cbStopbit.Name = "cbStopbit";
            this.cbStopbit.Size = new System.Drawing.Size(190, 28);
            this.cbStopbit.TabIndex = 1;
            // 
            // port
            // 
            this.port.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.port.Location = new System.Drawing.Point(140, 285);
            this.port.Name = "port";
            this.port.Size = new System.Drawing.Size(125, 36);
            this.port.TabIndex = 2;
            this.port.Text = "OK";
            this.port.UseVisualStyleBackColor = true;
            this.port.Click += new System.EventHandler(this.port_Click);
            // 
            // cbPortno
            // 
            this.cbPortno.Font = new System.Drawing.Font("굴림", 12F);
            this.cbPortno.FormattingEnabled = true;
            this.cbPortno.Items.AddRange(new object[] {
            "COM1",
            "COM2",
            "COM3",
            "COM4",
            "COM5"});
            this.cbPortno.Location = new System.Drawing.Point(149, 42);
            this.cbPortno.Name = "cbPortno";
            this.cbPortno.Size = new System.Drawing.Size(190, 28);
            this.cbPortno.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("굴림", 12F);
            this.label2.Location = new System.Drawing.Point(46, 87);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(97, 20);
            this.label2.TabIndex = 0;
            this.label2.Text = "Baud Rate";
            // 
            // PortSet
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.ClientSize = new System.Drawing.Size(404, 353);
            this.Controls.Add(this.port);
            this.Controls.Add(this.cbStopbit);
            this.Controls.Add(this.cbDatabits);
            this.Controls.Add(this.cbParity);
            this.Controls.Add(this.cbPortno);
            this.Controls.Add(this.cbBaudrate);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "PortSet";
            this.Text = "COM port set";
            this.Shown += new System.EventHandler(this.PortSet_Shown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        public System.Windows.Forms.ComboBox cbBaudrate;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        public System.Windows.Forms.ComboBox cbDatabits;
        private System.Windows.Forms.Label label5;
        public System.Windows.Forms.ComboBox cbStopbit;
        private System.Windows.Forms.Button port;
        public System.Windows.Forms.ComboBox cbPortno;
        private System.Windows.Forms.Label label2;
        public System.Windows.Forms.ComboBox cbParity;
    }
}