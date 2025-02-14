#include <iostream>

using namespace std;
using ll=long long;
ll a, b;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (a == b) cout << "0\n";
    else cout << (b - a - 1) << "\n";
    for (ll i = a + 1; i < b; i++) cout << i << " ";

    return 0;
}