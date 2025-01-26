#include <iostream>

using namespace std;

int n;
int dp[1000001];

int main() {
    cin >> n;

    dp[1]=1;

    for (int i = 2; i <= abs(n); i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000000;
    }

    if (n < 0 && (n % 2) == 0) {
        cout << "-1\n";
    } else if (n == 0) {
        cout << "0\n";
    } else {
        cout << "1\n";
    }

    cout << dp[abs(n)];

    return 0;
}
