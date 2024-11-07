#include "queue.h"
#include <string>

/*
    Given a number N, write a function that generates 
    and prints all binary numbers with decimal values 
    from 1 to N. This implementation should NOT use
    queues and run in O(N*log(N)) time.
*/
void printBinaryNaive(int n)
{
    for(int i=1;i<=n;i++){
        int a = i;
        int help=0;
        int l = 0;
        while(a/(pow(2,l))>0){
            l++;
        }
        l-=1;
        while(l>=0){
            if(a>=(pow(2,l))){
                help+=1*(pow(10,l));
                a-=pow(2,l);
            }
            l--;
        }
        cout<<help<<endl;
    }
}

/*
    Given a number N, write a function that generates 
    and prints all binary numbers with decimal values 
    from 1 to N. This implementation should make use of
    queues such that it runs in O(N) time. 
*/
void printBinaryQueue(int n)
{
    Queue<int> q1;
    q1.enqueue(1);
    int help = 1;
    int count=0;
    for(int i=2;i<=n;i++){
        if(i%2==0){
            q1.enqueue(q1.front()*10);
        }else{
            q1.enqueue(q1.front()*10+1);
            cout<<q1.dequeue()<<endl;;
        }
    }

    while(!q1.isEmpty()){
        cout<<q1.dequeue()<<endl;
    }

}