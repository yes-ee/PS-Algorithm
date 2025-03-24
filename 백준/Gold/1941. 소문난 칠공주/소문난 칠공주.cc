// 1. 백트래킹 조합 구하기
// 2. 개수 조건 만족하는지 확인
// 3. bfs로 모두 같은 그룹인지 확인

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using namespace std;

char arr[5][5];
int dx[4] = {1, 0,-1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;
int sel[5][5];
int vis[5][5];

int bfs(int x, int y) {
    queue<pii> q;
    int ret = 1;
    for (int i = 0; i < 5; i++) fill(vis[i], vis[i] + 5, 0);

    vis[x][y] = 1;
    q.push({x, y});

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || vis[nx][ny] || !sel[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
            ret++;
        }
    }
    return ret;
}

void re(int idx, int cnt) {
    if (cnt == 7) {
        // 조건에 맞는지 확인
        int ds = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (sel[i][j] && arr[i][j] == 'S') ds++;
            }
        }
        if (ds < 4) return;
        // 연결되어 있는지 확인
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (sel[i][j]) {
                    int ret = bfs(i, j);
                    if (ret == 7) ans++;
                    return;
                }
            }
        }
        return;
    }

    for (int i = idx + 1; i < 25; i++) {
        sel[i/5][i%5] = 1;
        re(i, cnt + 1);
        sel[i/5][i%5] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) cin >> arr[i][j];
    }
    re(-1, 0);
    cout << ans;
    return 0;
}