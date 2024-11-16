#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
ll sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());

	if (n % 2) sum = v[(n + 1) / 2];

	for (int i = n; i > (n + 1) / 2; i--) {
		sum += v[i] * 2;
	}

	cout << sum;

	return 0;
}