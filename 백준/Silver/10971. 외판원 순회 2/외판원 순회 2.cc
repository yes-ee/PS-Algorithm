// bruteforce

#include <bits/stdc++.h>

using namespace std;

int n;
int w[10][10];
int vis[10];
int ans = 1e9, sum;

void dfs(int cur, int cnt) {
    if (cnt == n) {
        // 정답 체크
        if (w[cur][0] == 0) return;
        ans = min(ans, sum + w[cur][0]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (vis[i] || w[cur][i] == 0) continue;
        vis[i] = 1;
        sum += w[cur][i];
        dfs(i, cnt + 1);
        sum -= w[cur][i];
        vis[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> w[i][j];
    }

    vis[0] = 1;
    dfs(0, 1);
    cout << ans;
    return 0;
}