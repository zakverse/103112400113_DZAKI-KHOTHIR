#include <iostream>
#include "queue.h"
using namespace std;
int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue_AL1(Q);

    cout<<"-----------------------------"<<endl;
    cout<<"H - T \t | Queue info"<<endl;
    cout<<"-----------------------------"<<endl;

    printInfo_AL1(Q);
    enqueue_AL1(Q, 5); printInfo_AL1(Q);
    enqueue_AL1(Q, 2); printInfo_AL1(Q);
    enqueue_AL1(Q, 7); printInfo_AL1(Q);
    dequeue_AL1(Q); printInfo_AL1(Q);
    enqueue_AL1(Q, 4); printInfo_AL1(Q);
    dequeue_AL1(Q); printInfo_AL1(Q);

    return 0;
}