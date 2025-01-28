#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using pii=pair<int, int>;

vector<string> arr;
int visited[1001][1001];
int tc;
int w, h;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs() {
    queue<pii> q;
    queue<pii> fq;
    int tm = 0;
    // get player location
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (arr[i][j] == 'J') {
                q.push({i, j});
                visited[i][j] = 1;
            } else if (arr[i][j] == 'F') {
                fq.push({i, j});
            }
        }
    }

    int fqs, qs, x, y, nx, ny;
    while (!q.empty()) {
        // update fire location
        fqs = fq.size();
        for (int i = 0; i < fqs; i++) {
            y = fq.front().first;
            x = fq.front().second;
            fq.pop();
            for (int k=0; k<4; k++) {
                ny = dy[k] + y;
                nx = dx[k] + x;
                if (nx < 0 || nx >= w || ny < 0 || ny >= h || arr[ny][nx] == 'F' || arr[ny][nx] == '#') continue;
                arr[ny][nx] = 'F';
                fq.push({ny, nx});
            }
        }

        // update player next location
        qs = q.size();
        tm++;
        for (int i = 0; i < qs; i++) {
            y = q.front().first;
            x = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++) {
                ny = y + dy[j];
                nx = x + dx[j];
                if (nx < 0 || nx >= w || ny < 0 || ny >= h) return tm;
                if (arr[ny][nx] == 'F'|| arr[ny][nx] == '#' || visited[ny][nx]) continue;
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> w;
    string s;
    for (int i = 0; i < h; i++) {
        cin >> s;
        arr.push_back(s);
    }

    int ret = bfs();
    if (ret < 0) cout << "IMPOSSIBLE";
    else cout << ret;
    cout << "\n";
}