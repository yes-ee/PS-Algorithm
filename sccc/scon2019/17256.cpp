#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;
	int x, y, z;
	int ra, rb, rc;

	cin >> a >> b >> c;
	cin >> x >> y >> z;

	ra = x - c;
	rb = y/b;
	rc = z - a;

	cout << ra << " "<< rb  << " "<< rc;

	return 0;
}