#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int n, m, sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i<= n; i++)
		q.push(i);

	for (int i = 0; i< m; i++) {
		int num;
		cin >> num;

		int len = q.size();
		int cnt = 0;

		while (1) {
			if (q.front() == num) {
				sum += min(cnt, len - cnt);
				q.pop();
				cnt = 0;
				break;
			}

			q.push(q.front());
			q.pop();
			cnt++;
		}
	}
	cout << sum;

	return 0;
}