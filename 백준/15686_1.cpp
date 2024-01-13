//tag: bruteforce

#include <iostream>
#include <vector>
#define pii pair<int, int>

using namespace std;

int n, m;
int city[50][50];
vector<pii> chicken;
vector<pii> house;
int ret = 9999;
int sum;

void getDist(vector<pii> list) {
	int hx, hy, cx, cy;

	for (int i = 0; i < house.size(); i++) {
		hx = house[i].first;
		hy = house[i].second;
		int cdis = 9999;

		for (int j = 0; j < list.size(); j++) {
			cx = list[j].first;
			cy = list[j].second;

			int ndis = abs(hx - cx) + abs(hy - cy);
			if (cdis > ndis)
				cdis = ndis;
		}
		sum += cdis;
	}

	if (sum < ret)
		ret = sum;
}

void solve(int start, vector<pii> list) {
	if (list.size() == m) {
		getDist(list);
		sum = 0;
		return;
	}

	for (int i = start + 1; i < chicken.size(); i++) {
		int cx = chicken[i].first;
		int cy = chicken[i].second;

		list.push_back({cx, cy});
		solve(i, list);
		list.erase(list.end() - 1);
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

	vector<pii> list;

	int cx, cy;

	for (int i = 0; i < chicken.size(); i++) {
		cx = chicken[i].first;
		cy = chicken[i].second;
		list.push_back({cx, cy});
		solve(i, list);
		list.erase(list.end() - 1);
	}

	cout << ret;
	return 0;
}