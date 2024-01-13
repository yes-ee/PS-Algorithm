#include <iostream>
#include <vector>

using namespace std;

int r, c, t;
vector<vector<int>> v;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<int> con;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		vector<int> one;
		for (int j = 0; j < c; j++) {
			int a;
			cin >> a;
			if (a == -1) {
				con.push_back(i);
			}
			one.push_back(a);
		}
		v.push_back(one);
	}

	while (t--) {
		vector<vector<int>> tmp(v);	//현재 상태 저장용, 업데이트는 v에

		// 확산
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (tmp[i][j] == 0 || tmp[i][j] == -1)
					continue;

				int cnt = 0;
				int diffuse = tmp[i][j] / 5;

				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (nx < 0 || ny < 0 || nx >= c || ny >= r)
						continue;
					if (tmp[ny][nx] == -1)
						continue;

					cnt++;
					v[ny][nx] += diffuse;
				}
				v[i][j] -= diffuse * cnt;
			}
		}

		// 공기청정기
		vector<vector<int>> tmp2(v);
		// 1열
		for (int i = 0; i < con[0] - 1; i++) {
			v[i + 1][0] = tmp2[i][0];
		}
		for (int i = con[1] + 2; i < r; i++) {
			v[i - 1][0] = tmp2[i][0];
		}

		//마지막열
		for (int i = 1; i <= con[0]; i++) {
			v[i - 1][c - 1] = tmp2[i][c- 1];
		}
		for (int i = con[1] ; i < r - 1; i++) {
			v[i + 1][c - 1] = tmp2[i][c- 1];
		}

		// 오른쪽
		for (int i = 1; i < c - 1; i++) {
			v[con[0]][i + 1] = tmp2[con[0]][i];
			v[con[1]][i + 1] = tmp2[con[1]][i];
		}

		// 왼쪽
		for (int i = 1; i < c; i++) {
			v[0][i - 1] = tmp2[0][i];
			v[r - 1][i - 1] = tmp2[r - 1][i];
		}
		v[con[0]][1] = 0;
		v[con[1]][1] = 0;
	}

	int sum = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (v[i][j] == -1)
				continue;
			sum += v[i][j];
		}
	}

	cout << sum;

	return 0;
}