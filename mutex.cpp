#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

void printline(int num){
    for(int i=0;i<num;i++){
        cout<<' ';
    }
    cout<<num<<endl;
}

void printmanylines(int num,mutex &mx){
    mx.lock();
    for(int i=0;i<3;i++){
        printline(num);
    }
    mx.unlock();
}

void createthread(int num,mutex &mx){
    thread t(printmanylines,num,ref(mx));
    t.detach(); //make current thread independent to prevent it from going out of scope
}

int main(){
    mutex mx; //C++ has a built-in mutex, this is a binary mutex though (only 1 resource)
    for(int i=0;i<5;i++){
        createthread(i,mx);
    }
    //below is just a timer to make sure main() does not end before the threads finish
    std::this_thread::sleep_for(chrono::seconds(2));
    return 0;
}