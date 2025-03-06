#include <iostream>

using namespace std;

int dp[1501000];
int n;
int t[1501000];
int p[1501000];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i-1], dp[i]);
        dp[i + t[i] - 1] = max(dp[i + t[i] - 1], dp[i-1] + p[i]);
    }

    cout << dp[n];

    return 0;
}