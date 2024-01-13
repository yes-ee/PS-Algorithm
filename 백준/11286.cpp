#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	while(n--) {
		int input;

		cin >> input;

		if (input == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top().second << "\n";
				pq.pop();
			}
		}
		else {
			pq.push({abs(input), input});
		}
	}
	return 0;
}