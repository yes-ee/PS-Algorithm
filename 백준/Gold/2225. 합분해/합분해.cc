#include <iostream>

using namespace std;
using ll = long long;

int n, k;
ll dp[201][201];
ll sum;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= k; i++) {
        sum = 0;
        for (int j = 0; j <= n; j++) {
            sum += dp[i-1][j];
            sum %= 1000000000;
            dp[i][j] = sum;
        }
    }

    cout << dp[k][n];

    return 0;
}