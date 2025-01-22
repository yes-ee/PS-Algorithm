#include <iostream>
#include <queue>

using namespace std;
using pii=pair<int, int>;

int n, k;
queue<pii> q;
int visited[2][500001];
int goal[1001];
int end_time;

int bfs() {
    visited[0][n] = 1;
    q.push({n, 0});
    while (!q.empty()) {
        int x = q.front().first;
        int time = q.front().second;
        q.pop();
        if (time >= end_time) continue;

        for (int nx : {x+1, x-1, x * 2}) {
            int nt = time +1;
            if (nx < 0 || nx > 500000) continue;
            if (!visited[nt%2][nx]) {
                visited[nt%2][nx] = 1;
                q.push({nx, nt});
            }
            // 만나는지 체크
            if (visited[nt%2][goal[nt]]) {
                return nt;
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> k;

    if (n==k) {
        cout <<0;
        return 0;
    }

    goal[0] = k;

    // 동생 위치 저장
    for (int i = 1; i <= 1000; i++) {
        goal[i] = goal[i-1] + i;
        if (goal[i] > 500000) {
            end_time = i - 1;
            break;
        }
    }
    int ans = bfs();

    cout << ans;

    return 0;
}