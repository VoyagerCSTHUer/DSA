#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Tuple{
public:
    int a, b, c;
};

bool cmp(const Tuple& A, const Tuple& B){
    return A.b < B.b;
}

int main(){
    int m;
    cin >> m;
    vector<Tuple> set;
    for(int i = 0; i < m; i++){
        int tem1, tem2, tem3;
        cin >> tem1 >> tem2 >> tem3;
        if(tem3 > 0){
            set.push_back({tem1, tem2, tem3});
        }
    }

    // 按照结束时间排序
    sort(set.begin(), set.end(), cmp);

    // 初始化dp数组
    vector<long long> dp(set.size());
    for(int i = 0; i < set.size(); i++){
        dp[i] = set[i].c;
    }

    // 使用二分搜索和DP来更新值
    for(int j = 1; j < set.size(); j++){
        // 二分搜索
        int low = 0, high = j - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(set[mid].b <= set[j].a){
                if(set[mid + 1].b <= set[j].a) low = mid + 1;
                else{
                    dp[j] = max(dp[j], dp[mid] + set[j].c);
                    break;
                }
            } else {
                high = mid - 1;
            }
        }
        if(low > high ) {if(set[j].c > dp[j]) dp[j] = set[j].c;}// 如果没有找到兼容的任务，只考虑当前任务的价值
        else dp[j] = max(dp[j], dp[low] + set[j].c); // 更新dp[j]
    }

    // 找出最大值
    long long ans = *max_element(dp.begin(), dp.end());
    cout << ans;

    return 0;
}
