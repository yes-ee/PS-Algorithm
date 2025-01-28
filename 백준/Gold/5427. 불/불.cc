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
            if (arr[i][j] == '@') {
                q.push({i, j});
                visited[i][j] = 1;
            } else if (arr[i][j] == '*') {
                fq.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        // update fire location
        int fqs = fq.size();
        for (int i = 0; i < fqs; i++) {
            int y = fq.front().first;
            int x = fq.front().second;
            fq.pop();
            for (int k=0; k<4; k++) {
                int ny = dy[k] + y;
                int nx = dx[k] + x;
                if (nx < 0 || nx >= w || ny < 0 || ny >= h || arr[ny][nx] == '*' || arr[ny][nx] == '#') continue;
                arr[ny][nx] = '*';
                fq.push({ny, nx});
            }
        }

        // update player next location
        int qsize = q.size();
        tm++;
        for (int i = 0; i < qsize; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int ny = y + dy[k];
                int nx = x + dx[k];
                if (nx < 0 || nx >= w || ny < 0 || ny >= h) return tm;
                if (arr[ny][nx] == '*'|| arr[ny][nx] == '#' || visited[ny][nx]) continue;
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
    return -1;
}

int main() {
    cin >> tc;
    while (tc--) {
        cin >> w >> h;
        string s;

        // init
        arr.clear();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) visited[i][j] = 0;
        }

        for (int i = 0; i < h; i++) {
            cin >> s;
            arr.push_back(s);
        }

        int ret = bfs();
        if (ret < 0) cout << "IMPOSSIBLE";
        else cout << ret;
        cout << "\n";
    }
}