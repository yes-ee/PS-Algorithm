#include <bits/stdc++.h>

using namespace std;

int n;
int visited[201];
int bit[201];
queue<int> q;

void print(int num) {
	string s = "";

	while (visited[num] != -1) {
		s += to_string(bit[num]);
		num = visited[num];
	}

	s += '1';

	reverse(s.begin(), s.end());
	cout << s << "\n";
}

void bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = -1;

	while (!q.empty()) {
		int num = q.front();
		q.pop();

		int nx = (num * 10 + 1) % n;

		if (!visited[nx]) {
			q.push(nx);
			bit[nx] = 1;
			visited[nx] = num;
		}
		if (nx == 0) {
			print(nx);
			return;
		}
		nx = (num * 10) % n;

		if (!visited[nx]) {
			q.push(nx);
			bit[nx] = 0;
			visited[nx] = num;
		}
		if (nx == 0) {
			print(nx);
			return;
		}
	}
}

int main() {
	while (1) {
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i <= n; i++) {
			visited[i] = 0;
			bit[i] = -1;
		}
		bfs();
	}

	return 0;
}