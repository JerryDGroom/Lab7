/*
*******************************************************************

Laboratory 7, Programming Exercise 1                    storesim.cs

Queue ADT || Group Project
Test program with random numbers
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

            int k = rand() % 4;     // this allows random number 0 - 3
            /*
            ==============================================================
            Used this for testing
            This prints out each random number to make sure its changing
            each time, and only pulling numbers 0 - 3
            ==============================================================
            cout << "This is the random number : " << k << endl;
            ==============================================================
            */
            cout << "This is the random number : " << k << endl;
            int storeDequeue = 0;

            if(k == 1)
            {
                custQ.enqueue(minute);
                totalServed++;
                storeDequeue = custQ.dequeue();
            }
            else if(k == 2)
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

