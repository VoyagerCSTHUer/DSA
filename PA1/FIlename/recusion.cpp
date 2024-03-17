#include<iostream>
using namespace std;

char a[503000];
char b[503000];

int ans(int i,int j){
    if(i < 0 || j < 0)return 0;
    for(;j>=0;j--){
        if(b[j] == a[i]){
            return max(1+ans(i-1,j-1),ans(i,j-1));
        }
    }
    return ans(i-1,j);
}

int main(){
    int alength,blength,tolerance;
    cin>>alength>>blength>>tolerance;
    for(int i=0;i<alength;i++)cin>>a[i];
    for(int j=0;j<blength;j++)cin>>b[j];
    cout<<alength+blength-2*(ans(alength,blength)-1);

}