#include <iostream>
#define DIV 1000000007

using namespace std;
using ll = long long;

ll dp[1001][1001];
int n, m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) dp[i][1] = 1;
    for (int i = 1; i <= m; i++) dp[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1]) % DIV;
        }
    }
    cout << dp[n][m];

    return 0;
}