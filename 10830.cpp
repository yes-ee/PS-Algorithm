#include <iostream>
#include <vector>

using namespace std;

long long n;
long long b;

void print(vector<vector<long long>> a) {
	for (long long i = 0; i < a.size(); i++) {
		for (long long j = 0; j < a.size(); j++) {
			cout << a[i][j] % 1000 << " ";
		}
		cout << "\n";
	}
}

// 행렬 간 곱셈
vector<vector<long long>> mpow(vector<vector<long long>> a, vector<vector<long long>> b) {
	long long n = a.size();
	long long m = b[0].size();
	long long inner = b.size();
	vector<vector<long long>> c(n, vector<long long>(m, 0));
	
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < m; j++) {
			for (long long k = 0; k < inner; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= 1000;
		}
	}
	return c;
}

vector<vector<long long>> pow(vector<vector<long long>> a, long long n) {
	if (n == 1) return a;

	vector<vector<long long>> x = pow(a, n/2);
	if (n % 2 == 0)
		return mpow(x, x);
	else
		return mpow(mpow(x, x), a);
}

int main() {
	cin >> n >> b;

	vector<vector<long long>> a(n, vector<long long>(n, 0));

	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	print(pow(a, b));
}