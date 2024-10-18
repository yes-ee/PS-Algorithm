// union find

#include <iostream>
#include <vector>

using namespace std;

int n;
int parent[300001];

// parent 초기값 저장
void init() {
	for (int i = 1; i<= n; i++)
		parent[i] = i;
}

int find(int x) {
	if (parent[x] == x) return x;

	return parent[x] = find(parent[x]);
}

// a b 같은 그룹에 저장
void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return; // 부모 같을 경우 저장 x
	
	parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	int a, b;

	init();

	for (int i = 0; i < n - 2; i++) {
		cin >> a >> b;

		merge(a, b);
	}

	int rt = find(1);

	for (int i = 2; i <= n; i++) {
		if (rt != find(i)) {
			cout << "1 " << i;
			return 0;
		}
	}

	return 0;
}