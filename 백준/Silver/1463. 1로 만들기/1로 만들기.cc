// bfs
// visited 처리
#include <iostream>
#include <queue>

using namespace std;
using pii=pair<int, int>;

int n;
int visited[1000001];

void bfs() {
    queue<pii> q;
    q.push({n, 0});
    visited[n] = 1;
    int x, nx, cnt;

    while (!q.empty()) {
        x = q.front().first;
        cnt = q.front().second;
        q.pop();
        
        if (x % 3 == 0) {
            nx = x / 3;
            if (!visited[nx]) {
                visited[nx] = 1;
                if (nx == 1) {
                    cout << cnt + 1;
                    return;
                }
                q.push({nx, cnt + 1});
            }
        }

        if (x % 2 == 0) {
            nx = x / 2;
            if (!visited[nx]) {
                visited[nx] = 1;
                if (nx == 1) {
                    cout << cnt + 1;
                    return;
                }
                q.push({nx, cnt + 1});
            }
        }

        nx = x - 1;
        if (!visited[nx]) {
            visited[nx] = 1;
            if (nx == 1) {
                cout << cnt + 1;
                return;
            }
            q.push({nx, cnt + 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    if (n == 1) {
        cout << "0";
        return 0;
    }

    bfs();
    return 0;
}