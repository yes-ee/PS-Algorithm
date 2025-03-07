#include <iostream>

using namespace std;

int t, w;
int arr[1001];
int dp[1001][31][3];
int ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t >> w;
    for (int i = 1; i <= t; i++) {
        cin >> arr[i];
        dp[i][0][1] = dp[i-1][0][1];
        if (arr[i] == 1) dp[i][0][1]++;
    }

    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= w; j++) {
            for (int k = 1; k <= 2; k++) {
                dp[i][j][k] = max(dp[i-1][j-1][3 - k], dp[i-1][j][k]) + (arr[i] == k ? 1 : 0);
            }
        }
    }

    for (int i = 0; i <= w; i++) {
        ans = max(ans, dp[t][i][1]);
        ans = max(ans, dp[t][i][2]);
    }
    cout << ans;
    return 0;
}