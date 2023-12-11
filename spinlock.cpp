#include <iostream>
#include <thread>
using namespace std;

class Spinlock{
public:
    bool locked=false;
    void acquire(){
        while(locked){}
        locked=true;
    }
    void release(){
        locked=false;
    }
};

void printline(int num){
    for(int i=0;i<num;i++){
        cout<<' ';
    }
    cout<<num<<endl;
}

void printmanylines(int num,Spinlock &spin){
    spin.acquire();
    for(int i=0;i<3;i++){
        printline(num);
    }
    spin.release();
}

void createthread(int num,Spinlock &spin){
    thread t(printmanylines,num,ref(spin));
    t.detach(); //make current thread independent to prevent it from going out of scope
}

int main(){
    Spinlock spin;
    for(int i=0;i<5;i++){
        createthread(i,spin);
    }
    //below is just a timer to make sure main() does not end before the threads finish
    std::this_thread::sleep_for(chrono::seconds(2));
    return 0;
}