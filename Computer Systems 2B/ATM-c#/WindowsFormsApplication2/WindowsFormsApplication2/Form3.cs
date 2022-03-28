using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

/*AC22005
 * 
 * Team */

namespace WindowsFormsApplication2
{
    public partial class Form3 : Form
    {
        //This form serves to show the balance of a certain account
        public Form3()
        {
            InitializeComponent();
            this.BackColor = Color.FromArgb(83, 215, 180);
        }

        //clicking "Back" closes the current form
        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Form3_Load(object sender, EventArgs e)
        {
            //label's 2 text becomes the account balance using the getAccountNum() functions
            label2.Text = "£" + Form1.currAcc.getBalance().ToString();
        }


    }
}
