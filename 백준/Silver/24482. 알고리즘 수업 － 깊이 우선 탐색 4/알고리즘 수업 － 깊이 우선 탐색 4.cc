#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r;
int dep[100001];
vector<vector<int>> v(100001);

void dfs(int st, int depth) {
    dep[st] = depth;

    for (auto nx: v[st]) {
        if (dep[nx] != -1) continue;
        dfs(nx, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> r;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) dep[i] = -1;

    for (int i = 1; i <= n; i++)
        sort(v[i].begin(), v[i].end(), greater<int>());

    dfs(r, 0);

    for (int i = 1; i <= n; i++) cout << dep[i] << "\n";

    return 0;
}