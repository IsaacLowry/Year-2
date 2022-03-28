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

    public partial class Form1 : Form
    {
        private PasswordCheck passCheck; //PasswordCheck Object that I can use to call the function in this class
        private CurrentAccount currAccount; //CurrentAccount object that I'll use to call the function in this class
        public static Account currAcc; //a variable that holds the current account

        public Form1()
        {

            passCheck = new PasswordCheck(); //create a new object
            currAccount = new CurrentAccount(); //create a new object
            
            InitializeComponent();
            this.BackColor = Color.FromArgb(83, 215, 180);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
           
            int x = Convert.ToInt32(textBox1.Text); // x becomes the text in textbox1 (account numb)
            int y = Convert.ToInt32(textBox2.Text); // y is the text in textbox2 (pass)

            //verifyPassword verifies if x and y are an account and password in a given array
            if (passCheck.verifyPassword(x, y, Form5.ac) == true)
            {
                //if found currAcc becomes the account that uses the given account number
                currAcc = currAccount.getAccount(x, Form5.ac);
                this.Hide(); // hide this form
                Form2 secondform = new Form2(); //create a new Form 2
                secondform.ShowDialog(); // and show form 2


            }
                //if the information doesnt match
            else
            {
                System.Windows.Forms.MessageBox.Show("Account information Incorrect. Please try again");
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {

        }

        private void button8_Click(object sender, EventArgs e)
        {

        }

        private void button10_Click(object sender, EventArgs e)
        {

        }

        private void button13_Click(object sender, EventArgs e)
        {

        }

        private void button11_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {

        }

        private void button12_Click(object sender, EventArgs e)
        {

        }

        private void button9_Click(object sender, EventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {

        }
    }

    //this class holds a function that is used to get an account
    class CurrentAccount
    {
        //parameters are a given integer and a given array of accounts
        public Account getAccount(int account_n, Account[] arr)
        {
            //it iterates through the given array looking for a matching account number
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i].getAccountNum() == account_n)
                {
                    //and returns said account number
                    return arr[i];
                }
            }
            return null;
        }
    }
    /* This class has a function that will check if an account exists and if its password is valid */
    class PasswordCheck
    {
        /* Parameters are an account number, a password and an Account array */
        public Boolean verifyPassword(int account_n, int pass, Account[] arr)
        {
            Boolean found = false;

            //to iterate through the array looking for a matching account
            for (int i = 0; i < arr.Length; i++)
            {
                if (account_n == arr[i].getAccountNum())
                {
                    if (arr[i].checkPin(pass) == true)  //if the account exists and the password is correct it reuturns true
                    {
                        return true;                   
                    }
                    else
                    {
                        found = false;
                    }
                }
                else
                {
                    found = false;
                }
            }

            return found; //else it returs falseh
        } 

    }

}
