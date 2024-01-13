#include <iostream>
#include <queue>
#include <algorithm>
#define pii pair<int, int>

using namespace std;


pii gem[300000];
int bag[300000];
priority_queue<int> pq;
int n, k;
long long ret;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, v;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		gem[i] = {m, v};
	}

	for (int i = 0; i < k; i++)
		cin >> bag[i];

	sort(bag, bag + k);
	sort(gem, gem + n, [](pii a, pii b) { 
		return a.first < b.first;
		});

	int j = 0;
	for (int i = 0; i < k; i++)
	{
		while (j < n && bag[i] >= gem[j].first) {
			pq.push(gem[j].second);
			j++;
		}
		if (!pq.empty()) {
			ret += pq.top();
			pq.pop();
		}
	}

	cout << ret;

	return 0;
}