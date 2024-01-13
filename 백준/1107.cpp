#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m, cnt;
vector<int> num;
int arr[10];

int check(int num) {
	string s = to_string(num);
	
	for (char c: s) {
		if (arr[c - '0'])
			return 0;
	}
	return 1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		arr[a] = true;
	}

	cnt = abs(n - 100);
	for (int i = 0; i < 1000000; i++) {
		if (check(i)) {
			int tmp = abs(n - i) + to_string(i).length();
			cnt = min(tmp, cnt);
		}
	}

	cout << cnt;

	return 0;
}