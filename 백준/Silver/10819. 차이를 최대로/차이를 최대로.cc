#include <iostream>

using namespace std;

int n, ans, sum;
int arr[8];
int visited[8];

void dfs(int cnt, int pre) {
	if (cnt == n) {
		ans = max(sum, ans);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;

		visited[i] = 1;
		sum += abs(pre - arr[i]);
		dfs(cnt + 1, arr[i]);
		visited[i] = 0;
		sum -= abs(pre -  arr[i]);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (int i = 0; i < n; i++) {
		sum = 0;
		visited[i] = 1;
		dfs(1, arr[i]);
		visited[i] = 0;
	}

	cout << ans;

	return 0;
}