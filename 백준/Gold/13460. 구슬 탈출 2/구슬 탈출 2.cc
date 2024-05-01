// bfs

#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int n, m, o, flag;
int x, y, cnt;
char board[100];
queue<pair<pii, int>> q;

void make(int x, int y, int mv) {
	if (flag)
		return;

	int nx = x;
	int ny = y;

	if ((mv < 0 && x < y) || (mv > 0 && x > y)) { // x, y 순으로 이동
		while (nx >= 0 && nx < n * m) {
			nx += mv;
			if (board[nx] == '#') {
				nx -= mv;
				break;
			}
			if (nx == o) {
				flag = 1;
				break;
			}
		}

		while (ny >= 0 && ny < n * m) {
			ny += mv;
			if (ny == o) {
				flag = 0;
				return;
			}
			if (board[ny] == '#' || ny == nx) {
				ny -= mv;
				break;
			}
		}
	} else {
		while (ny >= 0 && ny < n * m) {
			ny += mv;
			if (ny == o)
				return;
			if (board[ny] == '#') {
				ny -= mv;
				break;
			}
		}

		while (nx >= 0 && nx < n * m) {
			nx += mv;
			if (board[nx] == '#' || nx == ny) {
				nx -= mv;
				break;
			}
			if (nx == o) {
				flag = 1;
				break;
			}
		}
	}

	if (flag) {
		cout << cnt + 1;
		return ;
	}

	q.push({{nx, ny}, cnt + 1});
}

void bfs() {
	while (!q.empty() && !flag) {
		x = q.front().first.first;
		y = q.front().first.second;
		cnt = q.front().second;
		q.pop();

		if (cnt >= 10) {
			cout << "-1";
			return;
		}

		make(x, y, -m);
		make(x, y, m);
		make(x, y, -1);
		make(x, y, +1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int r, b;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
			int a;
			cin >> board[i];

			if (board[i] == 'R')
				r = i;
			else if (board[i] == 'B')
				b = i;
			else if (board[i] == 'O')
				o = i;
		}
	q.push({{r, b}, 0});

	bfs();

	return 0;
}
