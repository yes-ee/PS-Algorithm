#include <iostream>

using namespace std;

int g, p, cnt;
int parent[100001];

int find(int a) {
	if (parent[a] == a) return a;

	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b)
		parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> g >> p;

	for (int i = 0; i <= 100000; i++)
		parent[i] = i;
	for (int i = 0; i < p; i++) {
		int a;
		cin >> a;

		if (find(a) == 0)
			break;
		else {
			merge(find(a), find(a) - 1);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}