#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;

long long n;

matrix mul(matrix a, matrix b) {
	matrix c(a.size(), vector<long long>(b[0].size(), 0));

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < b.size(); k++) {
				c[i][j] += a[i][k] * b[k][j] % 1000000007;
			}
		}
	}

	return c;
}

matrix pow(matrix a, long long n) {
	if (n == 1)
		return a;

	matrix x = pow(a, n/2);

	if (n % 2 == 0)
		return mul(x, x);
	else
		return mul(mul(x, x), a);
}

int main() {
	cin >> n;

	matrix a = {{1, 1}, {1, 0}};
	matrix first = {{1}, {0}};

	matrix ans = mul(pow(a, n), first);

	cout << ans[1][0];

	return 0;
}