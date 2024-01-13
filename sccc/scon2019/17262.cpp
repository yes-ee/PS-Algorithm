#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, s, e;
	int min_e, max_s;
	cin >> n >> max_s >> min_e;

	for (int i = 1; i < n; i++) {
		cin >> s >> e;
		if (s > max_s)
			max_s = s;
		else if (e < min_e)
			min_e = e;
	}

	if (max_s > min_e)
		cout << max_s - min_e;
	else
		cout << "0";

	return 0;
}