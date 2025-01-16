#include <iostream>

using namespace std;

int n;
int ans;

int main() {
    cin >> n;

    if (n == 1 || n == 3) {
        cout << -1;
        return 0;
    }

    int rem = n % 5;
    if (rem % 2) {
        ans = (n - 5) / 5;
        ans += (rem + 5) / 2;
    } else {
        ans = n / 5;
        ans += rem / 2;
    }

    cout << ans;

    return 0;
}