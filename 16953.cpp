#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

long long a, b;

void bfs() {
	queue<pair<long long, int>> q;
	q.push({a, 1});

	while (!q.empty()) {
		long long num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		long long nxt1 = num * 2;
		long long nxt2 = num * 10 + 1;

		if (nxt1 == b || nxt2 == b) {
			cout << cnt + 1;
			return;
		}

		if (nxt1 <= 1e9) {
			q.push({nxt1, cnt + 1});
		}

		if (nxt2 <= 1e9) {
			q.push({nxt2, cnt + 1});
		}
	}

	cout << "-1";
}

int main() {
	cin >> a >> b;

	if (a == b) {
		cout << "1";
		return 0;
	}

	bfs();

	return 0;
}