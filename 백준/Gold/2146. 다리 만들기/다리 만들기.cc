// bfs

#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int n, m;
int arr[101][101];
int vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 30000;
int grp = 1;

int chk_dist(int x, int y, int g) {
    int dis = 30000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) continue;
            if (arr[i][j] == g) continue;
            dis = min(dis, abs(x - i) + abs(y - j) - 1);
        }
    }
    return dis;
}

void bfs(int x, int y) {
    queue<pii> q;
    q.push({x, y});
    vis[x][y] = 1;
    arr[x][y] = grp;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (arr[nx][ny] == 0 || vis[nx][ny]) continue;

            q.push({nx, ny});
            vis[nx][ny] = 1;
            arr[nx][ny] = grp;
        }
    }
}

int main() {
    cin >> n;
    m = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0 || vis[i][j]) continue;
            grp++;
            bfs(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) continue;
            ans = min(chk_dist(i, j, arr[i][j]), ans);
        }
    }

    cout << ans;
    return 0;
}