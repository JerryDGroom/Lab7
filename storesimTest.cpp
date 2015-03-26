/*
*******************************************************************

Laboratory 7, Programming Exercise 1                storesimTest.cs

Queue ADT || Group Project
NOT using random numbers
Jerry Groom & Christian Uwimana
3/22/2015

*******************************************************************
*/

// Simulates the flow of customers through a line in a store.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

// Use which ever implementation is currently configured.
#if LAB7_TEST1
#   include "QueueLinked.cpp"
#else
#   include "QueueArray.cpp"
#endif

using namespace std;

int main ()
{
#if LAB7_TEST1
    QueueLinked<int> custQ;      // Line (queue) of customers containing the
#else
    QueueArray<int> custQ;       // Line (queue) of customers containing the
#endif 				             //   time that each customer arrived and
    //   joined the line
    int simLength,               // Length of simulation (minutes)
        minute,                  // Current minute
        timeArrived,             // Time dequeued customer arrived
        waitTime,                // How long dequeued customer waited
        totalServed = 0,         // Total customers served
        totalWait   = 0,         // Total waiting time
        maxWait     = 0,         // Longest wait
        numArrivals = 0;         // Number of new arrivals

    // Seed the random number generator. Equally instructive to run the
    // simulation with the generator seeded and not seeded.


    srand( time(NULL) );

    cout << endl << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    // Put your code here to run this simulation. Use "rand()" to get
    // a pseudorandom number that you can use to calculate probabilities.

    minute = 1;
    while(minute <= simLength) // stop simulation once minute reaches given simLength
    {

        if(!custQ.isFull()) // This will run as long as the Queue is not full
        {

            int k = minute % 3;     // this gives only numbers 0-3 for minute values
            /*
            ==============================================================
            Table for testing verification
            ==============================================================
            minutes/modulo/customers served
            ==============================================================
            Minute	Modulo	=	Answer              Total Served
            1		1 % 3	=	0 customer served   =   0 customers
            2		2 % 3	=	1 customer served   =   1 customer
            3		3 % 3	=	2 customer served   =   3 customers
            4		4 % 3	=	0 customer served   =   3 customers
            5		5 % 3	=	1 customer served   =   4 customers
            6		6 % 3	=	2 customer served   =   6 customers
            7		7 % 3	=	0 customer served   =   6 customers
            8		8 % 3	=	1 customer served   =   7 customers
            9		9 % 3	=	2 customer served   =   9 customers
            ==============================================================
            */

            int storeDequeue = 0;

            if(k == 2)
            {
                custQ.enqueue(minute);
                totalServed++;
                storeDequeue = custQ.dequeue();
            }
            else if(k == 0)
            {
                custQ.enqueue(minute);
                custQ.enqueue(minute);
                totalServed+=2;
                storeDequeue = custQ.dequeue();
                storeDequeue = custQ.dequeue();
            }
            totalWait+=storeDequeue;
            if(storeDequeue > maxWait)
            {
                maxWait = storeDequeue;
            }

            /*
            ==============================================================
            Used this for testing
            ==============================================================
            int storeDeQueue = 0;
            cout << "Here is the Minute value : " << minute << endl;
            custQ.enqueue(minute);
            storeDeQueue = custQ.dequeue();
            cout << "Here is the DeQueued value : " << storeDeQueue << endl;
            ==============================================================
            */


        }
        minute++; // increment minute after each run through
    }
// Print out simulation results
    cout << endl;
    cout << "Customers served : " << totalServed << endl;
    cout << "Average wait     : " << setprecision(2)
         << double(totalWait)/totalServed << endl;
    cout << "Longest wait     : " << maxWait << endl;

    return 0;
}

