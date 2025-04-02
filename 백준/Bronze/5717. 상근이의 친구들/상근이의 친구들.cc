#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using namespace std;

int a, b;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    while (1) {
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        cout << a + b << "\n";
    }

    return 0;
}