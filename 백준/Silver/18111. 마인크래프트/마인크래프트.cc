#include <iostream>

using namespace std;

int n, m, b, ans;
int tm = 1e9;
int graph[500][500];

void fn(int mid) {
	int up = 0;
	int dwn = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] > mid)
				up += graph[i][j] - mid;
			else if (graph[i][j] < mid)
				dwn += mid - graph[i][j];
		}
	}

	if (b + up >= dwn) {
		int t = up * 2 + dwn;
		if (t <= tm) {
			ans = mid;
			tm = t;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			graph[i][j] = a;
		}
	}

	for (int i = 0; i <= 256; i++) {
		fn(i);
	}

	cout << tm << " " << ans;

	return 0;
}