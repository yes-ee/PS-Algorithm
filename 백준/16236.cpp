#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, stop, fish;
int ax, ay;	//다음 시작점
int map[20][20];
int visited[20][20];
int sum, tmp;
int cnt, s = 2;	// 먹은 물고기 수, 상어 크기
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

queue<tuple<int, int, int>> q;

void bfs() {
	q.push({ay, ax, 0});
	ay = 50;
	ax = 50;
	fish = 0;
	// 다음 갈 수 있는 곳이 없을 때까지 반복
	while (!q.empty()) {
		int y = get<0>(q.front());
		int x = get<1>(q.front());
		int t = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || nx >= n || ny >= n || visited[ny][nx] || map[ny][nx] > s)
				continue;
			
			// 방문 가능 위치
			visited[ny][nx] = 1;
			q.push({ny, nx, t + 1});  

			//물고기가 있는 경우
			if (map[ny][nx] > 0 && map[ny][nx] < s) {
				// 가장 가까운 거리인지 확인
				if (fish == 0 || (tmp == (t + 1))) {
					fish = 1;

					if (ay > ny || ((ay == ny) && (ax > nx))) {
						ay = ny;
						ax = nx;
						tmp = t + 1;
					}
				}
				//가장 가까운 거리가 아니면 탈출
				else
					return;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	// 시작위치 설정
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 9) {
				ay = i;
				ax = j;
				map[ay][ax] = 0;
			}
		}
	}

	while (!stop) {
		while (!q.empty())
			q.pop();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				visited[i][j] = 0;
		}
		
		bfs();

		if (fish) {
			map[ay][ax] = 0;
			sum += tmp;
			cnt++;
			if (cnt == s) {
				cnt = 0;
				s++;
			}
		}
		else
			stop = 1;
	}

	cout << sum;

	return 0;
}