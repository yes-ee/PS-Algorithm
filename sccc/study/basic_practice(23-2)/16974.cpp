#include <iostream>
#include <vector>

using namespace std;

vector<char> v;
int n;
unsigned long long x, cnt, bur[51], pat[51];

void re(unsigned long long x, int lv) {
	if (lv == 0) {
		cnt += 1;
		return;
	}

	if (x == bur[lv]) {
		cnt += pat[lv];
		return;
	}

	if (x <= 1)
		return;
	else if (x == 1 + bur[lv - 1]) {
		cnt += pat[lv - 1];
		return;
	}
	else if (x == 2 + bur[lv - 1]) {
		cnt += pat[lv - 1] + 1;
		return;
	}
	else if (x == 2 + bur[lv - 1] * 2) {
		cnt += pat[lv - 1] * 2 + 1;
	}
	else if (x < 1 + bur[lv - 1]) {
		re(x - 1, lv - 1);
		return;
	}
	else if (x < 2 + bur[lv - 1] * 2) {
		cnt += pat[lv - 1] + 1;
		re(x - 2 - bur[lv - 1], lv - 1);
	}
}

int main() {
	cin >> n >> x;

	bur[0] = 1;
	pat[0] = 1;
	for (int i = 1; i <= 50; i++) {
		bur[i] = bur[i - 1] * 2 + 3;
		pat[i] = pat[i -1] * 2 + 1;
	}

	re(x, n);
	cout << cnt;
	return 0;
}