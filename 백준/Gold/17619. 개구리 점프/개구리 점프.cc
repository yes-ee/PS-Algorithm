#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using namespace std;

int grp[100001];
int g = 1;
int n, q, a, b, c;
vector<tuple<int, int, int>> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        v.push_back({a, b, i + 1});
    }

    sort(v.begin(), v.end());
    auto cur = v[0];
    int s, e, idx;
    tie(s, e, idx) = cur;
    int ed = e;
    grp[idx] = g;

    for (int i = 1; i < n; i++) {
        cur = v[i];
        tie(s, e, idx) = cur;
        if (s <= ed) {
            ed = max(e, ed);
        } else {
            g++;
            ed = e;
        }
        grp[idx] = g;
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        if (grp[a] == grp[b]) cout << "1\n";
        else cout << "0\n"; 
    }

    return 0;
}