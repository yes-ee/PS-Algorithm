// union find

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using namespace std;

int p[1000001];
int cnt[1000001];
int n, a, b;
string cmd;

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    p[u] = v;
    cnt[v] += cnt[u];
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    fill(p, p + 1000001, -1);
    fill(cnt, cnt + 1000001, 1);
    while(n--) {
        cin >> cmd;
        if (cmd == "I") {
            cin >> a >> b;
            uni(a, b);
        } else {
            cin >> a;
            int r = find(a);
            cout << cnt[r] << "\n";
        }
    }

    return 0;
}