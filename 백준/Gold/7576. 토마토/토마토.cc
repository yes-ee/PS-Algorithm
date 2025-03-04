#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[1001][1001];
int ans;
queue<pair<pii, int>> q;

void bfs() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                q.push({{i, j}, 0});
            }
        }
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first.X + dx[i];
            int ny = cur.first.Y + dy[i];
            int nd = cur.second + 1;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (arr[nx][ny] == -1 || arr[nx][ny] == 1) continue;
            q.push({{nx, ny}, nd});
            ans = max(ans, nd);
            arr[nx][ny] = 1;
        }
    }

}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    bfs();

    // 다 익었는지 체크
    int all = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                all = 0;
                break;
            }
        }
    }
    if (!all) cout << -1;
    else cout << ans;

    return 0;
}