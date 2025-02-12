#include <iostream>

using namespace std;

int sum;
int m = 1e5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a;
    for (int i = 0; i < 7; i++) {
        cin >> a;
        if (a % 2 == 0) continue;
        sum += a;
        m = min(m, a);
    }
    if (sum) {
        cout << sum << "\n";
        cout << m;
    } else {
        cout << -1;
    }
    return 0;
}