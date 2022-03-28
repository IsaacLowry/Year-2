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
 * 
 * */

namespace WindowsFormsApplication2
{
    //This form Shows and performs the options in amounts a user can withdraw
    public partial class Form4 : Form
    {
        private int currentBalance; //this variable holds the currentBalance
        private static Object thisLock = new Object(); //this is going to be our lock. Static so threads share it

        public Form4()
        {
            InitializeComponent();
            this.BackColor = Color.FromArgb(83, 215, 180);
        }

        //If "Back" is pressed it closes the current form
        private void button4_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        //The event handler for clicking on "Withdraw £10"
        private void button1_Click(object sender, EventArgs e)
        {
            //if there isnt enough in the account
            if (Form1.currAcc.getBalance() < 10)
            {
                //Display an appropriate message and go back to the last form
                System.Windows.Forms.MessageBox.Show("Insuficient Funds");
                this.Close();
            }
                //if there is enough
            else
            {
                //check if we want to demonstrate a data race or not. 0 means yes, 1 means no,
                if (Form5.consistencyStatus == 0)
                {
                    //currentBalance holds the current balance in the account
                    currentBalance = Form1.currAcc.getBalance();
                    
                    //add 1 to timerStatus, default is always 0
                    Form5.timerStatus++;

                    //If the timerStatus is 1 that means that this is the first thread trying to withdraw money
                    if (Form5.timerStatus == 1)
                    {
                        //we delay this thread by 3 seconds
                        Thread.Sleep(3000);
                        //and then we take out the amount
                        Form1.currAcc.setBalance(currentBalance - 10);
                        //display the appropriate message
                        System.Windows.Forms.MessageBox.Show("Succesfully withdrawn £10");
                    }

                        //if the timerstatus isn't 1 that means its the second thread
                    else
                    {
                        //remove the amount wanted from the account
                        Form1.currAcc.setBalance(currentBalance - 10);
                        //display the appropriate message
                        System.Windows.Forms.MessageBox.Show("Succesfully withdrawn £10");
                        //reset the timerstatus
                        Form5.timerStatus = 0;
                    }
                    //and close the form
                    this.Close();
                    
                }
                //if we want to demonstrate using a lock for concurrency
                if (Form5.consistencyStatus == 1)
                {
                    //we lock the critical part of the code
                    lock (thisLock)
                    {
                        //currentBalance will hold the current account balance
                        currentBalance = Form1.currAcc.getBalance();
                        //add 1 to the timer status
                        Form5.timerStatus++;

                        //if the timerStatus is 1 that means its the first thread
                        if (Form5.timerStatus == 1)
                        {
                            //sleep thread for 3 seconds
                            Thread.Sleep(3000);
                            //set the new balance
                            Form1.currAcc.setBalance(currentBalance - 10);
                            //display the appropriate message
                            System.Windows.Forms.MessageBox.Show("Succesfully withdrawn £10");
                        }
                            //if its not 1 then its the second thread
                        else
                        {
                            //set the balance
                            Form1.currAcc.setBalance(currentBalance - 10);
                            //Display the appropriate message
                            System.Windows.Forms.MessageBox.Show("Succesfully withdrawn £10");
                            //reset the timerstatus
                            Form5.timerStatus = 0;
                        }
                        //and close the current form and go back
                        this.Close();                    
                    }
                }
            }
        }

        //The event handler for clicking on "Withdraw £50"
        private void button2_Click(object sender, EventArgs e)
        {
            //if there isnt enough in the account
            if (Form1.currAcc.getBalance() < 50)
            {
                //Display an appropriate message and go back to the last form
                System.Windows.Forms.MessageBox.Show("Insuficient Funds");
                this.Close();
            }
            
                //if there is enough
            else
            {
                //check if we want to demonstrate a data race or not. 0 means yes, 1 means no
                if (Form5.consistencyStatus == 0)
                {
                    //currentBalance holds the current balance in the account
                    currentBalance = Form1.currAcc.getBalance();

                    //add 1 to timerStatus, default is always 0
                    Form5.timerStatus++;

                    //If the timerStatus is 1 that means that this is the first thread trying to withdraw money
                    if (Form5.timerStatus == 1)
                    {
                        //we delay this thread by 3 seconds
                        Thread.Sleep(3000);

                        //and then we take out the amount
                        Form1.currAcc.setBalance(currentBalance - 50);

                        //and display the appropriate message
                        System.Windows.Forms.MessageBox.Show("Succesfully withdrawn £50");
                    }
                    
                        //if the timerstatus isn't 1 that means its the second thread
                    else
                    {
                        //remove the amount wanted from the account
                        Form1.currAcc.setBalance(currentBalance - 50);
                        //display the appropriate message
                        System.Windows.Forms.MessageBox.Show("Succesfully withdrawn £50");
                        //reset the timerStatus
                        Form5.timerStatus = 0;
                    }
                    //and close the form
                    this.Close();

                }

                //if we want to demonstrate using a lock for concurrency
                if (Form5.consistencyStatus == 1)
                {
                    //we lock the critical part of the code
                    lock (thisLock)
                    {
                        //currentBalance will hold the current account balance
                        currentBalance = Form1.currAcc.getBalance();
                        //add 1 to the timer status
                        Form5.timerStatus++;

                        //if the timerStatus is 1 that means its the first thread
                        if (Form5.timerStatus == 1)
                        {
                            //sleep thread for 3 seconds
                            Thread.Sleep(3000);
                            //set the new balance
                            Form1.currAcc.setBalance(currentBalance - 50);
                            //display the appropriate message
                            System.Windows.Forms.MessageBox.Show("Succesfully withdrawn £50");
                        }

                        //if its not 1 then its the second thread
                        else
                        {
                            //set the new balance
                            Form1.currAcc.setBalance(currentBalance - 50);
                            //display the appropriate message
                            System.Windows.Forms.MessageBox.Show("Succesfully withdrawn £50");
                            //reset the timerStatus
                            Form5.timerStatus = 0;
                        }
                        //and exit the current form
                        this.Close();      
                    }
                }
            }
        }

        //The event handler for clicking on "Withdraw £500"
        private void button3_Click(object sender, EventArgs e)
        {
            //check if there is enough balance. If there isn't:
            if (Form1.currAcc.getBalance() < 500)
            {
                //Display the appropriate message
                System.Windows.Forms.MessageBox.Show("Insuficient Funds");
                //and close the form
                this.Close();
            }
                //if there is enough money in the account:
            else
            {
                //check if we want to demonstrate lack of consistency or consistency. 0 means a datarace will happen. 1 means it won't
                if (Form5.consistencyStatus == 0)
                {
                    //get the current balance
                    currentBalance = Form1.currAcc.getBalance();
                    //add one to the timer status
                    Form5.timerStatus++;

                    //if the timer status is equal to one that means its the first thread
                    if (Form5.timerStatus == 1)
                    {
                        //sleep the thread for 3 seconds
                        Thread.Sleep(3000);
                        //then set its balance
                        Form1.currAcc.setBalance(currentBalance - 500);
                        //and display the appropriate message
                        System.Windows.Forms.MessageBox.Show("Succesfully withdrawn £500");
                    }
                        //if it isn't one then its the second thread
                    else
                    {
                        //set the new balance
                        Form1.currAcc.setBalance(currentBalance - 500);
                        //display the appropriate message
                        System.Windows.Forms.MessageBox.Show("Succesfully withdrawn £500");
                        //and reset the timer status
                        Form5.timerStatus = 0;
                    }
                    //return back to the previous form
                    this.Close();

                }

                //if consistency status is 1 we want to demonstrate using a lock
                if (Form5.consistencyStatus == 1)
                {
                    //we lock the critical part of the code
                    lock (thisLock)
                    {
                        //we get the current balance and hold it in a variable
                        currentBalance = Form1.currAcc.getBalance();

                        //add one to the timerstatus
                        Form5.timerStatus++;

                        //if timer status is 1 that means it's the first thread
                        if (Form5.timerStatus == 1)
                        {
                            //sleep the thread for 3 seconds
                            Thread.Sleep(3000);
                            //set the balance of the current account
                            Form1.currAcc.setBalance(currentBalance - 500);
                            //and display the appropriate message
                            System.Windows.Forms.MessageBox.Show("Succesfully withdrawn £500");
                        }

                            //if it's not one then it means it's the second thread
                        else
                        {
                            //set the balance
                            Form1.currAcc.setBalance(currentBalance - 500);
                            //display the appropriate message
                            System.Windows.Forms.MessageBox.Show("Succesfully withdrawn £500");
                            //and reset the timerStatus
                            Form5.timerStatus = 0;
                        }
                        //and close the current form
                        this.Close();      
                    }
                }
            }
        }
    }
}
