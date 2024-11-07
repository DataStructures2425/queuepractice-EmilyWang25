#include <chrono>
#include "binary.h"
using namespace std;
using namespace std::chrono;

/* 
    Test your code here - measure the difference in time to show that
    the queue implementation is faster!
*/
int main()
{
    // An example of measuring the time it takes for an algorithm to execute
    auto start0 = high_resolution_clock::now(); 
    printBinaryNaive(7);
    auto stop0 = high_resolution_clock::now();\

    auto diff0 = duration_cast<nanoseconds>(stop0-start0); 
    cout<<"time for native:"<<diff0.count()<<endl;
    
    auto start = high_resolution_clock::now(); // time before cout
    printBinaryQueue(7);
    auto stop = high_resolution_clock::now(); // time after cout

    auto diff = duration_cast<nanoseconds>(stop-start); // get difference
    cout <<"time for queue:"<<diff.count()<<endl;
}