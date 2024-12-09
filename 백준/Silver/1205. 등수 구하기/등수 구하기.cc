#include <bits/stdc++.h>

using namespace std;

int n, sc, p, idx = -1;

vector<int> v;

int main() {
	cin >> n >> sc >> p;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end(), greater<int>());

	if (n == 0) {
		cout << "1";
		return 0;
	}

	if (n == p && v[n-1] == sc) {
		cout << "-1";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (v[i] <= sc) {
			idx = i;
			break;
		}
	}

	if (idx == -1 && n < p) idx = n;
	else if (idx == -1) idx = -2;

	cout << idx + 1;

	return 0;
}