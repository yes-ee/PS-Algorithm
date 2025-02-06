// bit masking
#include <iostream>

using namespace std;

int n, ans;

int main() {
    cin >> n;
    while (n) {
        if (n % 2) ans++;
        n = n >> 1;
    }
    cout << ans;
}