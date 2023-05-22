#include <iostream>
#include <queue>
#define MAX 1000000

using namespace std;
int valid[MAX];
typedef pair<int, int> P;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t, k;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k;
		priority_queue<P> max_heap;
		priority_queue<P, vector<P>, greater<P>> min_heap;

		for (int j = 0; j < k; j++) {
			char c;
			int a;
			cin >> c >> a;

			if (c == 'I') {
					max_heap.push({a, j});
					min_heap.push({a, j});
					valid[j] = true;
			}
			else if (c == 'D') {
				if (a == 1) {
					while (!max_heap.empty() && !valid[max_heap.top().second])
						max_heap.pop();
					if (!max_heap.empty()) {
						valid[max_heap.top().second] = false;
						max_heap.pop();
					}
				}
				else {
					while (!min_heap.empty() && !valid[min_heap.top().second])
						min_heap.pop();
					if (!min_heap.empty()) {
						valid[min_heap.top().second] = false;
						min_heap.pop();
					}
				}
			}
		}

		while (!max_heap.empty() && !valid[max_heap.top().second])
			max_heap.pop();
		while (!min_heap.empty() && !valid[min_heap.top().second])
			min_heap.pop();
		if (max_heap.empty() && min_heap.empty())
			cout << "EMPTY\n";
		else
			cout << max_heap.top().first << " " << min_heap.top().first << "\n";
	}

	return 0;
}