// 3차원 bfs
// 최단 거리 구하기

#include <iostream>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

int l, r, c;
char arr[31][31][31];
int dis[31][31][31];
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};
tuple<int, int, int> st;
tuple<int, int, int> ed;
int nx, ny, nz;

void bfs(int x, int y, int z){
    queue<tuple<int, int, int>> q;
    dis[x][y][z] = 0;
    q.push({x, y, z});
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 6; i++) {
            nx = get<0>(cur) + dx[i];
            ny = get<1>(cur) + dy[i];
            nz = get<2>(cur) + dz[i];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= r || nz >= c) continue;
            if (dis[nx][ny][nz] >= 0 || arr[nx][ny][nz] =='#') continue;
            dis[nx][ny][nz] = dis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            q.push({nx, ny, nz});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (1) {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) return 0;

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    cin >> arr[i][j][k];
                    dis[i][j][k] = -1;
                    if (arr[i][j][k] == 'S') {
                        st = {i, j, k};
                    } else if (arr[i][j][k] == 'E') {
                        ed = {i, j, k};
                    }
                }
            }
        }

        bfs(get<0>(st), get<1>(st), get<2>(st));
        if (dis[get<0>(ed)][get<1>(ed)][get<2>(ed)] == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << dis[get<0>(ed)][get<1>(ed)][get<2>(ed)] << " minute(s).\n";
    }
    return 0;
}
