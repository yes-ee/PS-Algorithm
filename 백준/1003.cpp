#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
0 1 0
1 0 1
2 1 1 f(1) + f(0)
3 f(2) + f(1)
4 f(3) + f(2)
5 f(4) + f(3)
*/

typedef pair<int, int> P;

vector<P> v(41);

void dp(int n) {
	v[0] = {1, 0};
	v[1] = {0, 1};

	for (int i = 2; i < n; i++) {
		v[i].first = v[i - 1].first + v[i - 2].first;
		v[i].second = v[i - 1].second + v[i - 2].second;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;

	dp(41);

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		cout << v[n].first << " " << v[n].second << "\n";
	}
	return 0;
}