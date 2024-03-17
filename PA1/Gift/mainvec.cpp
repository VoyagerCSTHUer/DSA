#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, P;
    cin >> n >> P;

    vector<int> dp(P + 1, 1e9); // 初始化为一个较大的值
    dp[0] = 0; // 初始状态，总花费为0

    for (int i = 1; i <= n; i++) {
        int a1, a2;
        cin >> a1 >> a2;

        for (int j = P; j >= 0; j--) {
            dp[j] = min(dp[j], dp[max(0, j - a1)] + a1);
            dp[j] = min(dp[j], dp[max(0, j - a2)] + a2);
        }
    }

    // 统计总花费不超过 P 的方案数
    long long ans = 0;
    for (int j = 0; j <= P; j++) {
        if (dp[j] <= P) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
