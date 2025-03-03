#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int n, m;
int tm;
int arr[301][301];
int narr[301][301];
int vis[301][301];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt, ans;
int nx, ny;

void bfs(int x, int y) {
    queue<pii> q;
    q.push({x, y});
    vis[x][y] = 1;

    // 주변 보고 마이너스
    for (int j = 0; j < 4; j++) {
        int ax = x + dx[j];
        int ay = y + dy[j];
        if (ax < 0 || ay < 0 || ax >= n || ay >= m) continue;
        if (arr[ax][ay] == 0) narr[x][y]--;
    }
    if (narr[x][y] < 0) narr[x][y] = 0;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (vis[nx][ny] || arr[nx][ny] == 0) continue;
            // 주변 보고 마이너스
            for (int j = 0; j < 4; j++) {
                int ax = nx + dx[j];
                int ay = ny + dy[j];
                if (ax < 0 || ay < 0 || ax >= n || ay >= m) continue;
                if (arr[ax][ay] == 0) narr[nx][ny]--;
            }
            if (narr[nx][ny] < 0) narr[nx][ny] = 0;
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    while (1) {
        int flag = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j]) flag = 0;
            }
        }
        if (flag) {
            cout << "0";
            return 0;
        }

        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                narr[i][j] = arr[i][j];
                vis[i][j] = 0;
            }
        }

        // bfs로 돌면서 얼음 주위 체크
        // 동시에 그룹 체크
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] || arr[i][j] == 0) continue;
                cnt++;
                bfs(i, j);
            }
        }

        if (cnt >= 2) {
            cout << ans;
            return 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = narr[i][j];
                vis[i][j] = 0;
            }
        }
        ans++;
    }
}

//0105