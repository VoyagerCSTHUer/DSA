#include <iostream>
#include <vector>

std::string longestCommonSubstring(const std::string &str1, const std::string &str2) {
    int m = str1.length();
    int n = str2.length();

    // 创建一个二维动态规划数组
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    int maxLength = 0; // 记录最长公共子串的长度
    int endIndex = 0;  // 记录最长公共子串在str1中的结束索引

    // 填充动态规划数组
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // 根据最长公共子串的结束索引和长度提取最长公共子串
    if (maxLength == 0) {
        return ""; // 没有找到公共子串
    } else {
        return str1.substr(endIndex - maxLength + 1, maxLength);
    }
}

int main() {
    std::string str1, str2;
    std::cout << "输入第一个字符串: ";
    std::cin >> str1;
    std::cout << "输入第二个字符串: ";
    std::cin >> str2;

    std::string result = longestCommonSubstring(str1, str2);

    if (result.empty()) {
        std::cout << "没有找到公共子串" << std::endl;
    } else {
        std::cout << "最长公共子串为: " << result << std::endl;
    }

    return 0;
}