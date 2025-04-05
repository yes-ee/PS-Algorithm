#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using namespace std;

int n, m;
map<string, int> mp;
vector<pair<int, string>> ans;

bool cmp(pair<int, string> &a, pair<int, string> &b) {
    if (a.first == b.first) {
        if (a.second.length() == b.second.length()) return a.second < b.second;
        return a.second.length() > b.second.length();
    }
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    string s;
    for (int i = 0;i < n; i++) {
        cin >> s;
        if (s.length() < m) continue;
        mp[s]++;
    }

    for (auto c : mp) {
        ans.push_back({c.second, c.first});
    }
    sort(ans.begin(), ans.end(), cmp);
    for (auto c : ans) cout << c.second << "\n";

    return 0;
}