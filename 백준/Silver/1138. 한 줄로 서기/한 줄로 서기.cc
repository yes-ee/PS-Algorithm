#include <bits/stdc++.h>

using namespace std;

int n;
int arr[10];
int line[10];
int visited[10];
int flag;

bool chk() {
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (line[j] > line[i]) {
				cnt++;
			}
		}
		if (cnt != arr[line[i]]) {
			return false;
		}
	}

	return true;
}

void dfs(int idx, int cnt) {
	if (flag) return;

	if (cnt == n) {
		if (chk()) flag = 1;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		if (flag) return;

		visited[i] = 1;
		line[cnt] = i;
		dfs(i + 1, cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;

	for (int i = 0; i <n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		flag = 0;
		visited[i] = 1;
		line[0] = i;
		dfs(i, 1);
		visited[i] = 0;
		if (flag) break;
	}

	for (int i = 0; i < n; i++) {
		cout << line[i] + 1<< " ";
	}

	return 0;
}