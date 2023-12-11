#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class Semaphore{
public:
    Semaphore(int r):resources(r){}
    int resources;
    mutex mx;
    condition_variable cv;
    void wait(){
        unique_lock<mutex> lock(mx);
        while(!resources){
            cv.wait(lock);
        }
        resources--;
    }
    void signal(){
        unique_lock<mutex> lock(mx);
        resources++;
        cv.notify_one();
    }
};

void printline(int num){
    for(int i=0;i<num;i++){
        cout<<' ';
    }
    cout<<num<<endl;
}

void printmanylines(int num,Semaphore &sem){
    sem.wait();
    for(int i=0;i<3;i++){
        printline(num);
    }
    sem.signal();
}

void createthread(int num,Semaphore &sem){
    thread t(printmanylines,num,ref(sem));
    t.detach(); //make current thread independent to prevent it from going out of scope
}

int main(){
    Semaphore sem(1);
    for(int i=0;i<5;i++){
        createthread(i,sem);
    }
    //below is just a timer to make sure main() does not end before the threads finish
    std::this_thread::sleep_for(chrono::seconds(2));
    return 0;
}