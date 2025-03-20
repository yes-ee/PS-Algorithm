// union find

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using namespace std;

int p[1000001];
int t, n, k, a, b;

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) {
        return false;
    }
    p[u] = v;
    return  true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Scenario " << i + 1<< ":\n";
        cin >> n;
        fill(p, p + n, -1);
        cin >> k;
        for (int j =0; j<k; j++) {
            cin >> a >> b;
            uni(a, b);
        }
        cin >> k;
        for (int j =0; j<k; j++) {
            cin >> a >> b;
            if (find(a) == find(b)) cout << "1\n";
            else cout << "0\n";
        }
        cout << "\n";
    }

    return 0;
}