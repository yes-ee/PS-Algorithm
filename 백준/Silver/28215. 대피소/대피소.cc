#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, ans = 999999;
int dis[51][51];
vector<pair<int, int>> v;

void dfs(int idx, vector<int> sel) {
    if (sel.size() == k) {
        int m = 0;
        for (int i = 0; i < n; i++) {
            int d = 999999;
            for (int j : sel) {
                d = min(d, dis[i][j]);
            }
            m = max(m, d);
        }

        ans = min(m, ans);
        return;
    }

    for (int i = idx; i < n; i++) {
        sel.push_back(i);
        dfs(i + 1, sel);
        sel.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x, y;

        cin >> x >> y;

        v.push_back({x, y});
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dis[i][j] = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
        }
    }

    vector<int> sel;

    dfs(0, sel);

    cout << ans;

    return 0;
}