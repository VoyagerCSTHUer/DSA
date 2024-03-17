#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Tuple{
public:
    int a;
    int b;
    int c;
};

bool cmp(Tuple A, Tuple B){
    if(A.a < B.a) return true;
    if(A.a == B.a && A.b <= B.b) return true;
    return false;
}

int main(){
    int m;
    cin >> m;
    vector<Tuple> set(m);

    int cnt = 0;
    for(int i = 0; i < m; i++){
        int tem1, tem2, tem3;
        cin >> tem1 >> tem2 >> tem3;
        if(tem3 > 0){
            set[cnt].a = tem1;
            set[cnt].b = tem2;
            set[cnt].c = tem3;
            cnt++;
        }
    }

    sort(set.begin(), set.begin() + cnt, cmp);
    vector<long long int> dp(cnt);

    for(int i = 0; i < cnt; i++){
        dp[i] = set[i].c;
    }

    for(int j = 0; j < cnt; j++){
        for(int k = j - 1; k >= 0; k--){
            if(set[k].b <= set[j].b){
                (dp[k] + set[j].c > dp[j])? dp[j] = dp[k] + set[j].c : dp[j];
            }
        }
    }

    long long int ans = 0;
    for(int i = 0; i < cnt; i++){
        (dp[i] > ans)? ans = dp[i] : ans;
    }

    cout<<ans;

    return 0;
}