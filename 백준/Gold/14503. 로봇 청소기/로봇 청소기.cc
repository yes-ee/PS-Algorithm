//1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
//2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
//	- 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
//	- 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
//3. 현재 칸의 주변 $4$칸 중 청소되지 않은 빈 칸이 있는 경우,
//	- 반시계 방향으로 $90^\circ$ 회전한다.
//	- 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
//	- 1번으로 돌아간다.


#include <iostream>

using namespace std;

int n, m;
int r, c, d, ans;
int arr[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}


	while (1) {
		int nx;
		int ny;
		int flag = 0;
		// 1. 현재 칸이 청소 안 된 경우 청소하고 리셋
		if (arr[r][c] == 0) {
			arr[r][c] = -1;
			ans++;
		}
		// 2. 주변 4칸 먼저 확인
		for (int i = 0; i < 4; i++) {
			ny = r + dy[i];
			nx = c + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

			// 주변에 청소 안 된 칸이 있으면 3번으로
			if (arr[ny][nx] == 0) {
				flag = 1;
				break;
			}
		}
		// 청소 안 된 빈 칸이 없으면
		// 방향에 따라 후진
		if (!flag)
		{
			if (d == 0)
			{
				ny = r + 1;
				nx = c;
			}
			else if (d == 1)
			{
				ny = r;
				nx = c - 1;
			}
			else if (d == 2)
			{
				ny = r - 1;
				nx = c;
			}
			else
			{
				ny = r;
				nx = c + 1;
			}

			// 후진 불가능 시 종료
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == 1)
				break;

			// 후진 가능 시 후진
			r = ny;
			c = nx;
			continue;
		}
		// 청소 안 된 빈칸이 있으면
		else {
			for (int i = 0; i < 4; i++) {
				// 회전
				if (d == 0) {
					ny = r;
					nx = c - 1;
				} else if (d == 1) {
					ny = r - 1;
					nx = c;
				} else if (d == 2) {
					ny = r;
					nx = c + 1;
				} else {
					ny = r + 1;
					nx = c;
				}

				d = (d + 3) % 4;
				// 없는 경우 방향만 변경
				if (ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == 1) {
					continue;
				}

				// 회전한 곳의 앞 칸이 청소 x 면 이동
				if (arr[ny][nx] == 0)
				{
					r = ny;
					c = nx;
					break;
				}
			}
		}
	}

	cout << ans;

	return 0;
}