#include<iostream>
#include<vector>
#include<string>
using namespace std; 


int cost[42];
int dp[42][1000003];
int n;
int P;

int main(){
    int n,P;
    std::cin>>n>>P;
    int temp_one,temp_two;
    int ground_price = 0;
    for(int i=1;i<=n;i++){
        std::cin>>temp_one>>temp_two;
        ground_price += std::min(temp_one,temp_two);
        cost[i] = abs(temp_one - temp_two);
    }

    if(P < ground_price){
        std::cout<<0;
        return 0;
    }
    int rest = P - ground_price;

    dp[1][cost[1]] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=rest;j++){
            dp[i][j] = (j >= cost[i])? (dp[i-1][j] + dp[i-1][j-cost[i]]) : dp[i-1][j];
        }
    }

    //test
    for(int i=1;i<n;i++){cout<<cost[i]<<' ';}
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=rest;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }

    int ans = 0;
    
    for(int i=0;i<=rest;i++){
        ans += dp[n][i];
    }
    std::cout<<ans;
    return 0;
}