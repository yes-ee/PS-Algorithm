#include <iostream>
#include <queue>

using namespace std;

int n, k;
queue<int> q;
int visited[2][500001];
int end_time;
int goal;

int bfs() {
    int time = 1;
    visited[0][n] = 1;
    q.push(n);
    while (!q.empty()) {
        // bfs depth 깊이 세기 위해 사이즈 사용
        int sz = q.size();
        goal += time;

        if (goal > 500000) return -1;

        // 이전에 방문한 적 있는지 확인
        if (visited[time%2][goal]) {
            return time;
        }

        for (int i = 0; i < sz; i++) {
            int x = q.front(); q.pop();

            for (int nx : {x+1, x-1, x * 2}) {
                if (goal == nx) {
                    return time;
                }
                if (nx < 0 || nx > 500000) continue;
                if (!visited[time%2][nx]) {
                    visited[time%2][nx] = 1;
                    q.push(nx);
                }
            }
        }
        time++;
    }
    return -1;
}

int main() {
    cin >> n >> k;

    if (n==k) {
        cout <<0;
        return 0;
    }

    goal = k;

    int ans = bfs();

    cout << ans;

    return 0;
}