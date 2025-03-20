#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using namespace std;
int p[1000001];
int ed[1000001];
int n, m;
int a, b;
int ans;

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;

    for (int i = ed[u] + 1; i <= v; i++) {
        p[i] = u;
        i = ed[i];
    }

    p[v] = u;
    ed[u] = ed[v];
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        ed[i]= i;
        p[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        uni(a, b);
    }

    for (int i = 1; i <= n; i++) {
        ans++;
        i = ed[i];
    }

    cout << ans;

    return 0;
}