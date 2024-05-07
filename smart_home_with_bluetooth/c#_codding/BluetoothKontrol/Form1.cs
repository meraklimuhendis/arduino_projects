using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;
using System.Diagnostics;

namespace BluetoothKontrol
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        
        String scom;
        SerialPort port;
        private void button1_Click(object sender, EventArgs e)
        {
             
        }
        void adddevice()
        {
            try
            {  //add device n os
                Process p = Process.Start("c:\\Windows\\System32\\DevicePairingWizard.exe");//here write ur own windows drive
                while (true)
                {
                    if (p.HasExited) //determine if process end
                        break;
                }
                //generate busy com ort list
                /*
                                List<string> tList = new List<string>();
                                listBox1.Items.Clear();
                                foreach (string s in SerialPort.GetPortNames())
                                {
                                    tList.Add(s);
                                }
                                tList.Sort();
                                listBox1.Items.Add("NO PORT");
                                listBox1.Items.AddRange(tList.ToArray());
                                listBox1.SelectedIndex = 0;
                 */
                textBox3.Text = textBox3.Text + Environment.NewLine + "COMPORT GENERATED";
            }
            catch (Exception ee)
            {
                if (DialogResult.Retry == MessageBox.Show("CANT FIND UR ADDED DEVICE..", "Problem occured", MessageBoxButtons.AbortRetryIgnore, MessageBoxIcon.Error))
                    adddevice();
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Control.CheckForIllegalCrossThreadCalls = false;
        }

     
        private void button3_Click(object sender, EventArgs e)
        {
           
        }
        bool connectbluetooth()
        {
            try
            {
                if (textBox1.TextLength != 0)
                {
                    //scom = listBox1.SelectedItem.ToString();
                    scom = textBox1.Text;
                    port = new SerialPort(scom, 9600, Parity.None, 8, StopBits.One);
                    port.Open();
                    port.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);
                    textBox3.Text = textBox3.Text + Environment.NewLine + "baglantı açıldı"; ;
                    return true;
                }
                else
                    MessageBox.Show("com portu seçiniz", "port yok", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return false;
            }
            catch (Exception a)
            {
                if (DialogResult.Retry == MessageBox.Show(a.Message, "problem occured", MessageBoxButtons.AbortRetryIgnore, MessageBoxIcon.Warning))
                    connectbluetooth();
                else
                    return false;
                return false;
            }
        }

        private void DataReceivedHandler(
                       object sender,
                       SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            string indata = sp.ReadExisting();
            textBox3.AppendText(indata);

        }
      
        bool send(string text)
        {
            try
            {
                port.WriteTimeout = 10000;//define how much time wait for send data
               port.WriteLine(text);
                return true;
            }
            catch (Exception a)
            {
                if (DialogResult.Retry == MessageBox.Show(a.Message, "Problem occured", MessageBoxButtons.AbortRetryIgnore, MessageBoxIcon.Warning))
                    send(text);
                else
                    return false;
                return false;
            }
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            port.Close();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            connectbluetooth();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            send(textBox2.Text);
            textBox1.ResetText();
        }

        private void button3_Click_1(object sender, EventArgs e)
        {
            port.Close();
        }

        private void button4_Click_1(object sender, EventArgs e)
        {
            send("priz1ac");
        }

        private void button5_Click(object sender, EventArgs e)
        {
            send("priz1kapat");
        }

        private void button17_Click(object sender, EventArgs e)
        {
            send("priz2ac");
        }

        private void button16_Click(object sender, EventArgs e)
        {
            send("priz2kapat");
        }

        private void button6_Click(object sender, EventArgs e)
        {
            send("oda1ledac");
        }

        private void button7_Click(object sender, EventArgs e)
        {
            send("oda1kirmizi");
        }

        private void button8_Click(object sender, EventArgs e)
        {
            send("oda1mavi");
        }

        private void button9_Click(object sender, EventArgs e)
        {
            send("oda1yesil");
        }

        private void button10_Click(object sender, EventArgs e)
        {
            send("oda1ledkapat");
        }

        private void button15_Click(object sender, EventArgs e)
        {
            send("oda2ledac");
        }

        private void button14_Click(object sender, EventArgs e)
        {
            send("oda2kirmizi");
        }

        private void button13_Click(object sender, EventArgs e)
        {
            send("oda2mavi");
        }

        private void button12_Click(object sender, EventArgs e)
        {
            send("oda2yesil");
        }

        private void button11_Click(object sender, EventArgs e)
        {
            send("oda2ledkapat");
        }

        private void button23_Click(object sender, EventArgs e)
        {
            send("priz4ac");
        }

        private void button22_Click(object sender, EventArgs e)
        {
            send("priz4kapat");
        }

        private void button28_Click(object sender, EventArgs e)
        {
            send("powerledaz");
        }

        private void button27_Click(object sender, EventArgs e)
        {
            send("powerledorta");
        }

        private void button26_Click(object sender, EventArgs e)
        {
            send("powerledyuksek");
        }

        private void button24_Click(object sender, EventArgs e)
        {
            send("powerledkapat");
        }

        private void button19_Click(object sender, EventArgs e)
        {
            send("elektrikleriac");
        }

        private void button18_Click(object sender, EventArgs e)
        {
            send("elektriklerikapat");
        }

        private void button21_Click(object sender, EventArgs e)
        {
            send("oda2sicaklik");
        }

        private void button20_Click(object sender, EventArgs e)
        {
            send("oda2nem");
        }

        
    }
}

