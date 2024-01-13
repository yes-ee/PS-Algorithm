#include <iostream>
#include <queue>

using namespace std;
int n, k;
queue<int> q;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	cout << "<";
	while (1) {
		for (int i = 0; i < k - 1; i++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		cout << q.front();
		q.pop();
		if (!q.empty())
			cout << ", ";
		else {
			cout << ">";
			break;
		}
	}
	return 0;
}