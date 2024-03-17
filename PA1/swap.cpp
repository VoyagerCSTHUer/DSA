#include<iostream>
using namespace std;

void swap(int & a,int & b){
    int c;
    c = a;
    a = b;
    b = c;
    return ;
}

int main(){
    int a = 2;
    int b = 8;
    swap(a,b);
    cout<<a<<' '<<b;
    return 0;
}