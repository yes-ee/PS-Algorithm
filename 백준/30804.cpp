#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 1; i < 9; i++) {
		for (int j = i; j <= 9; j++) {
			int cnt = 0;
			for (int k = 0; k < n; k++) {
				if (v[k] != i && v[k] != j) {
					cnt = 0;
					continue;
				}
				cnt++;
				m = max(cnt, m);
			}
		}
	}

	cout << m;

	return 0;
}