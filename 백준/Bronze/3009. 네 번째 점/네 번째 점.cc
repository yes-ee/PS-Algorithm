#include <iostream>
#include <map>

using namespace std;

int x, y;

int main() {
	int a, b;
	map<int, int> mx;
	map<int, int> my;

	for (int i = 0; i < 3; i++) {
		cin >> a >> b;

		if (mx[a])
			mx[a]++;
		else
			mx[a] = 1;

		if (my[b])
			my[b]++;
		else
			my[b] = 1;
	}

	for (auto x : mx)
		if (x.second == 1)
			cout << x.first << " ";
	
	for (auto y : my)
		if (y.second == 1)
			cout << y.first;

	return 0;
}