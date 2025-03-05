#include <iostream>
#include <queue>

using namespace std;
using pii=pair<int,int>;

int k;
int w, h;
int arr[201][201];
int vis[31][201][201];
int dx1[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy1[8] = {1, -1, 1, -1, 2, 2, -2, -2};
int dx2[4] = {0, 0, 1, -1};
int dy2[4] = {1, -1, 0, 0};
int ed;

void bfs(int x, int y) {
    queue<pair<pii, int>> q; // x, y, k
    q.push({{0, 0}, k});
    vis[k][x][y] = 0;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = cur.first.first + dx1[i];
            int ny = cur.first.second + dy1[i];
            int nk = cur.second - 1;

            if (nk < 0) break;
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if (arr[nx][ny] == 1 || vis[nk][nx][ny] >= 0) continue;

            if (nx == (h-1) && ny == (w-1)) {
                ed = 1;
                cout << vis[cur.second][cur.first.first][cur.first.second] + 1;
                return;
            }
            q.push({{nx, ny}, nk});
            vis[nk][nx][ny] = vis[cur.second][cur.first.first][cur.first.second] + 1;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.first.first + dx2[i];
            int ny = cur.first.second + dy2[i];
            int nk = cur.second;

            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if (arr[nx][ny] == 1 || vis[nk][nx][ny] >= 0) continue;

            if (nx == (h-1) && ny == (w-1)) {
                ed = 1;
                cout << vis[cur.second][cur.first.first][cur.first.second] + 1;
                return;
            }
            q.push({{nx, ny}, nk});
            vis[nk][nx][ny] = vis[cur.second][cur.first.first][cur.first.second] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> w >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> arr[i][j];
        }
    }

    if (w == 1 && h == 1) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < h; j++) {
            fill(vis[i][j], vis[i][j] + w, -1);
        }
    }

    bfs(0, 0);

    if (!ed) cout << -1;

    return 0;
}