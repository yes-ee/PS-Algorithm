#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using namespace std;

string s;
int len;
int vis[10];
vector<char> v;
int ans;
map<char, int> m;

bool check() {
    for (int i = 1; i < len; i++) {
        if (v[i] == v[i-1]) return false;
    }
    return true;
}

bool check(string s) {
    for (int i = 1; i < len; i++) {
        if (s[i] == s[i-1]) return false;
    }
    return true;
}

int fac(int n) {
    int ret = 1;
    for (int i = 2; i <= n; i++) ret *= i;
    return ret;
}

void re(int cnt) {
    if (cnt == len) {
        if (check()) ans++;
        return;
    }

    for (int i = 0; i < len; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        v.push_back(s[i]);
        re(cnt + 1);
        v.pop_back();
        vis[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    len = s.length();
    sort(s.begin(), s.end());
    do {
        if (check(s)) ans++;
    } while (next_permutation(s.begin(), s.end()));

    for (auto c : s) {
        m[c]++;
    }
    cout << ans;
    return 0;
}