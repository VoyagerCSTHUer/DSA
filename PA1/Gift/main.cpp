#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> cost;
    int n;
    int P;
    vector<int> dp;
    std::cin>>n>>P;
    cost.resize(n+1);
    dp.resize(P+1);
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

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = rest; j >= cost[i]; j--) {
            dp[j] += dp[j - cost[i]];
        }
    }

    int ans = 0;
    
    for(int i=0;i<=rest;i++){
        ans += dp[i];
    }
    std::cout<<ans;
    return 0;
}