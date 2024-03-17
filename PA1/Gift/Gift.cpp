#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

int cost[43];

int FindSolution(int n){
    int c[int(pow(2,n/2))];
    for(int i=0;i<int(pow(2,n/2));i++){
        c[i] = 0;
       for(int j=0;j<n;j++){
            c[i] += ((i & int(pow(2,j))) >> j) * cost[j];
       }
    }
    int rest = n - n/2;
    for(int i=0;i<int(pow(2,n/2));i++){
        
    }
}

int main(){
    int n,P;
    cin>>n>>P;
    int temp_one,temp_two;
    for(int i=0;i<n;i++){
        cin>>temp_one>>temp_two;
        cost[i] = abs(temp_one - temp_two);
    }
    cout<<FindSolution(n);
}

