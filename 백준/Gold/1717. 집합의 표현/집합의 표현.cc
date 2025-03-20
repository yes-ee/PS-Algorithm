// union find

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using namespace std;

int p[1000001];
int n, m;
int cmd, a, b;

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;    // 부모 같으면
    p[u] = v;
    return true;   // 부모 다르면 합치고 true 리턴 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    // init
    fill(p, p + n + 1, -1);
    while (m--) {
        cin >> cmd >> a >> b;
        if (cmd == 0) { // union
            uni(a, b);
        } else {
            if (find(a) == find(b)) { // 같은 그룹
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }

    return 0;
}