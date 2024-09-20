#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;
int arr[8];

void f(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < n; i++) {
		if (arr[i]) continue;

		arr[i] = 1;
		v.push_back(i + 1);
		f(cnt + 1);
		v.pop_back();
		arr[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	f(0);

	return 0;
}