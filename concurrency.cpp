#include <iostream>
#include <thread>
using namespace std;

void printline(int num){
    for(int i=0;i<num;i++){
        cout<<' ';
    }
    cout<<num<<endl;
}

void printmanylines(int num){
    for(int i=0;i<3;i++){
        printline(num);
    }
}

void createthread(int num){
    thread t(printmanylines,num);
    t.detach();
}

int main(){
    for(int i=0;i<5;i++){
        createthread(i);
    }
    return 0;
}
