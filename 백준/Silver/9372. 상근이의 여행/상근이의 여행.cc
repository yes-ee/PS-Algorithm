#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using namespace std;

int t;
int n, m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        int a, b;
        for (int i = 0; i < m; i++) cin >> a >> b;
        cout << n - 1 << "\n";
    }

    return 0;
}