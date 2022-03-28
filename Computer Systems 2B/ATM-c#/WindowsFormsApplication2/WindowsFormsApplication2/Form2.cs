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
    //Form 2 shows Options to "Take out Cash", "Check Balance" or "Exit"
    public partial class Form2 : Form
    {

        public Form2()
        {
            InitializeComponent();
            this.BackColor = Color.FromArgb(83, 215, 180);
        }

        //if "Show Balance" button is clicked
        private void button2_Click(object sender, EventArgs e)
        {
            // Create a new form3 object, hide the current one and show form3 object
            Form3 thirdform = new Form3();
            this.Hide();
            thirdform.ShowDialog();
            this.Show();
        }

        //if "Exit" is clicked
        private void button3_Click(object sender, EventArgs e)
        {
            //exits the application
            Application.Exit();
            
        }

        //if "Take out cash" option is clicked
        private void button1_Click(object sender, EventArgs e)
        {
            //Create a new form4 object, hide the current one and show form4 object
            Form4 fourthform = new Form4();
            this.Hide();
            fourthform.ShowDialog();
            this.Show();
        }
    }
}
