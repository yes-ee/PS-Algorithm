#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
priority_queue<int, vector<int>, greater<int>> l;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;

		cin >> a >> b >> c;

		pq.push({b, c});
	}

	int s = pq.top().first;
	int e = pq.top().second;
	pq.pop();
	l.push(e);

	for (int i = 1; i < n; i++) {
		s = pq.top().first;
		e = pq.top().second;
		pq.pop();

		if (l.top() > s) {
			l.push(e);
		}
		else {
			l.pop();
			l.push(e);
		}
	}

	cout << l.size();

	return 0;
}