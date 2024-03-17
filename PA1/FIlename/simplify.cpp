#include<iostream>
using namespace std;

char a[503000];
char b[503000];
int **dp;


int main(){
    int alength,blength,tolerance;
    cin>>alength>>blength>>tolerance;
    for(int i=1;i<=alength;i++)cin>>a[i];
    for(int j=1;j<=blength;j++)cin>>b[j];
    dp = new int*[alength+1];
    for(int i=0;i<=alength;i++){
        dp[i] = new int[blength+1];
    }

    for(int i=0;i<=alength;i++){
        for(int j=0;j<=blength;j++){
            dp[i][j] = 0;
        }
    }

    for(int i=1;i<=alength;i++){
        for(int j=1;j<=blength;j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout<<alength+blength-2*dp[alength][blength]<<endl;
    //cout<<alength+blength-2*len;

    /*for(int i=0; i < alength; i++){
        delete[] dp[i];
    }
    delete[] dp;*/

    return 0;
}
