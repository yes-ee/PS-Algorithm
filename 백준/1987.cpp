#include <iostream>
#include <vector>
#include <string>

using namespace std;

int r, c, ans;
vector<string> v;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int alpha[26];

void dfs(int y, int x, int cnt) {
	if (cnt > ans)
		ans = cnt;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= c || ny >= r)
			continue;

		int next = v[ny][nx] - 'A';
		if (alpha[next])
			continue;

		alpha[next] = 1;
		dfs(ny, nx, cnt + 1);
		alpha[next] = 0;
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	alpha[v[0][0] - 'A'] = 1;
	dfs(0, 0, 1);

	cout << ans;

	return 0;
}