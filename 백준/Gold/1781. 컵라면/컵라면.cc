#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long sum, t = 1;
priority_queue<long long> pq;
vector<long long> v[200000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		
		v[a - 1].push_back(b);
	}

	while (n--) {
		for (auto c : v[n]) {
			pq.push(c);
		}

		if (pq.empty()) continue;

		sum += pq.top();

		pq.pop();
	}

	cout << sum;

	return 0;
}