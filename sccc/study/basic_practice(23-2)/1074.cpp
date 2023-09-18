#include <iostream>
#include <cmath>

using namespace std;

int n, r, c, cnt;

void re(int r, int c, int len) {
	if (r == 0 && c == 0) {
		cout << cnt;
		return;
	}

	int sz = len/2;
	int block = sz * sz;

	cnt += (r/sz) * block * 2 + (c/sz) * block;
	re(r % sz, c % sz, sz);
}

int main() {
	cin >> n >> r >> c;

	int len = pow(2, n);

	re(r, c, len);
}