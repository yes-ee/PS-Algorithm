#include <iostream>
#include <string>

using namespace std;

int t, a, b;
int dp[1000001];

int chk(string n) {
    int up = 1;
    
    if (n[0] > n[1]) return 0;

    for (int i = 1; i < n.length(); i++) {
        if (n[i] == n[i - 1]) return 0;
        if (up && n[i] < n[i - 1]) up = 0;
        if (!up && n[i] > n[i - 1]) return 0;
    }

    if (up) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 120; i <= 1000000; i++) {
        dp[i] = dp[i - 1] + chk(to_string(i));
    }

    cin >> t;
    
    while (t--) {
        cin >> a >> b;

        cout << dp[b] - dp[a - 1] << "\n";
    }

    return 0;
}