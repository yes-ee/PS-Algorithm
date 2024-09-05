#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (a == 0) {
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else
				cout << "0\n";
		}
		else
			pq.push(a);
	}

	return 0;
}