#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#define MAX 1000000
using namespace std;

int n, len;
int arr[MAX];
int pre[MAX];
vector<pair<int, int>> l;
stack<int> s;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first < b.first;
}

void solve(void) {
	int idx;

	for (int i = 0; i < n; i++) {
		pre[i] = -1;
	}

	l.push_back({arr[0], 0});

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > l.back().first) {
			idx = l.size();
			l.push_back({arr[i], i});
			pre[i] = l[idx - 1].second;
		}
		else {
			idx = lower_bound(l.begin(), l.end(), make_pair(arr[i], i), cmp) - l.begin();
			l[idx] = {arr[i], i};
			if (idx != 0)
				pre[i] = l[idx - 1].second;
		}
	}

	len = l.size();
	idx = l[len - 1].second;
	for (int i = len - 1; i >= 0; i--) {
		s.push(arr[idx]);
		idx = pre[idx];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	solve();

	cout << len << "\n";
	for (int i = 0; i < len; i++) {
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}
