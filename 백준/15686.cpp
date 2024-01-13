//tag: bruteforce

#include <iostream>
#include <vector>
#define pii pair<int, int>

using namespace std;

int n, m;
int city[50][50];
vector<pii> chicken;
vector<pii> house;
int list[13];
int ret = 9999;
int sum;

void getDist() {
	int hx, hy, cx, cy;

	for (int i = 0; i < house.size(); i++) {
		hx = house[i].first;
		hy = house[i].second;
		int cdis = 9999;

		for (int j = 0; j < 13; j++) {
			if (list[j] == 0)
				continue;
			cx = chicken[j].first;
			cy = chicken[j].second;

			int ndis = abs(hx - cx) + abs(hy - cy);
			if (cdis > ndis)
				cdis = ndis;
		}
		sum += cdis;
	}

	if (sum < ret)
		ret = sum;
}

void solve(int cnt, int start) {
	if (cnt == m) {
		getDist();
		sum = 0;
		return;
	}

	for (int i = start + 1; i < chicken.size(); i++) {
		list[i] = 1;
		solve(cnt + 1, i);
		list[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1)
				house.push_back({i, j});
			else if (city[i][j] == 2)
				chicken.push_back({i, j});
		}
	}

	for (int i = 0; i < chicken.size(); i++) {
		list[i] = 1;
		solve(1, i);
		list[i] = 0;
	}

	cout << ret;
	return 0;
}