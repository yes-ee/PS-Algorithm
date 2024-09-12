#include <iostream>

using namespace std;

int n, p;
int visited[98];

int main() {
	cin >> n >> p;

	int nxt = n % p;
	int cnt = 1;
	int ans;

	// 방문 시 visited에 순서 기록
	while (1) {
		if (visited[nxt]) {
			ans = cnt - visited[nxt];
			cout << ans;
			break;
		}
		visited[nxt] = cnt;
		cnt++;
		nxt = (nxt * n) % p;
	}

	return 0;
}