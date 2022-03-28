using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

/*AC22005
 * Made by: Andrei Lins
 * Team 33*/

namespace WindowsFormsApplication2
{
    //This is our main form. It holds the accounts information and lets us choose what type of demonstration we want to do
    public partial class Form5 : Form
    {
        //and array of accounts
        public static Account[] ac = new Account[3];
        //an integer that we use to tell what thread we're dealing with
        public static int timerStatus;
        //an integer we use to tell which demonstration we want to do
        public static int consistencyStatus;

        public Form5()
        {
            //we initiate the values as given to us by the proffessor's code
            ac[0] = new Account(300, 1111, 111111);
            ac[1] = new Account(750, 2222, 222222);
            ac[2] = new Account(3000, 3333, 333333);
            
            //and just initate the integers to 0
            timerStatus = 0;
            consistencyStatus = 0;
            InitializeComponent();
            this.BackColor = Color.FromArgb(83, 215, 180);
        }
        //if we want to show a data race we click this button
        private void button1_Click(object sender, EventArgs e)
        {
            //create two new threads and start them
            Thread ATM_1 = new Thread(new ThreadStart(ThreadProc));
            Thread ATM_2 = new Thread(new ThreadStart(ThreadProc));
            ATM_1.Start();
            ATM_2.Start();
        }

        //if we want to demonstrate a lock we click this button
        private void button2_Click(object sender, EventArgs e)
        {
            //set the consistency status to 1 so we know what we're doing
            consistencyStatus = 1;
            //and create two new threads and start them
            Thread ATM_1 = new Thread(new ThreadStart(ThreadProc));
            Thread ATM_2 = new Thread(new ThreadStart(ThreadProc));
            ATM_1.Start();
            ATM_2.Start();
        }

        //this function simply creates a new object of Form1 type and shows it's dialog
        private void ThreadProc()
        {
            Form1 frm = new Form1();
            frm.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit(); 
        }

    }
    /*
*   The Account class encapusulates all features of a simple bank account
*/
    public class Account
    {
        //the attributes for the account
        private int balance;
        private int pin;
        private int accountNum;

        // a constructor that takes initial values for each of the attributes (balance, pin, accountNumber)
        public Account(int balance, int pin, int accountNum)
        {
            this.balance = balance;
            this.pin = pin;
            this.accountNum = accountNum;
        }

        //getter and setter functions for balance
        public int getBalance()
        {
            return balance;
        }
        public void setBalance(int newBalance)
        {
            this.balance = newBalance;
        }

        /*
         *   This funciton allows us to decrement the balance of an account
         *   it perfomes a simple check to ensure the balance is greater tha
         *   the amount being debeted
         *   
         *   reurns:
         *   true if the transactions if possible
         *   false if there are insufficent funds in the account
         */
        public Boolean decrementBalance(int amount)
        {
            if (this.balance > amount)
            {
                balance -= amount;
                return true;
            }
            else
            {
                return false;
            }
        }

        /*
         * This funciton check the account pin against the argument passed to it
         *
         * returns:
         * true if they match
         * false if they do not
         */
        public Boolean checkPin(int pinEntered)
        {
            if (pinEntered == pin)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        public int getAccountNum()
        {
            return accountNum;
        }

    }
}
