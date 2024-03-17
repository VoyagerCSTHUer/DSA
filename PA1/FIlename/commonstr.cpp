#include<iostream>
using namespace std;

char a[5030];
char b[5030];
int dp[5030][5030];

int main(){
    int alength,blength,tolerance;
    cin>>alength>>blength>>tolerance;
    for(int i=0;i<alength;i++)cin>>a[i];
    for(int j=0;j<blength;j++)cin>>b[j];

    for(int i=0;i<alength;i++){
        for(int j=0;j<blength;j++){
            for(int k=i;k>=0;k--){
                if(a[k] == b[j]){
                    if(j == 0 || k == 0)dp[i][j] = max(1,dp[i][j]);
                    else dp[i][j] = max(dp[i][j],dp[k-1][j-1] + 1);
                }
                else{
                    if(j == 0 || k == 0)dp[i][j] = max(0,dp[i][j]);
                    else dp[i][j] = max(dp[i][j],dp[k-1][j-1]);
                }
            }
            for(int k=j;k>=0;k--){
                if(b[k] == a[j]){
                    if(j == 0 || k == 0)dp[i][j] = max(1,dp[i][j]);
                    else dp[i][j] = max(dp[i][j],dp[i-1][k-1] + 1);
                }
                else{
                    if(j == 0 || k == 0)dp[i][j] = max(0,dp[i][j]);
                    else dp[i][j] = max(dp[i][j],dp[i-1][k-1]);
                }
            }
            dp[i][j] = max(max(dp[i][j],dp[i-1][j-1]),max(dp[i][j-1],dp[i-1][j]));
        }
    }

    for(int i=0;i<alength;i++){
        for(int j=0;j<blength;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<dp[alength-1][blength-1]<<endl;
    //cout<<alength+blength-2*len;

    return 0;
}
