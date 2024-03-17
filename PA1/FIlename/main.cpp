#include<iostream>
using namespace std;

char a[503000];
char b[503000];

int changetimes(char* a,char* b,int a_size,int b_size){
    if(a_size == 0 || b_size == 0){
        return max(a_size,b_size);
    }
    if(*a == *b){
        return changetimes(a+1,b+1,a_size-1,b_size-1);
    }
    if(*a == *(b+1)){
        return changetimes(a+1,b+2,a_size-1,b_size-2) + 1;
    }
    if(*(a+1) == *b){
        return changetimes(a+2,b+1,a_size-2,b_size-1) + 1;
    }
    return changetimes(a+1,b+1,a_size-1,b_size-1) + 1;
}

int expchangetimes(char* a,char* b,int a_size, int b_size){
    if(a_size == 0 || b_size == 0){
        return max(a_size,b_size);
    }
    if(*a == *b)return changetimes(a+1,b+1,a_size-1,b_size-1);
    return 1 + min(changetimes(a,b+1,a_size,b_size-1),changetimes(a+1,b,a_size-1,b_size));
}

int main(){
    int alength,blength,tolerance;
    cin>>alength>>blength>>tolerance;
    for(int i=0;i<alength;i++)cin>>a[i];
    for(int j=0;j<blength;j++)cin>>b[j];

    //if(expchangetimes(a,b,alength,blength)>tolerance)cout<<-1<<endl;
    //else 
    cout<<expchangetimes(a,b,alength,blength)<<endl;

    return 0;
}