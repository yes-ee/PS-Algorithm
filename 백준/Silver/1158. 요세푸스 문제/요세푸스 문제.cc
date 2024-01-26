#include <iostream>
#include <queue>

using namespace std;

int n, k;
queue<int> q;
vector<int> v;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		q.push(i);

	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}

		v.push_back(q.front());
		q.pop();
	}

	cout << "<";

	for (int i = 0; i < n; i++) {
		if (i == n -1)
			cout << v[i] << ">";
		else
			cout << v[i] << ", ";
	}

	return 0;
}