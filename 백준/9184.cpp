#include <iostream>
#define MAX 21
using namespace std;

int dp[MAX][MAX][MAX];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);
	
	if (dp[a][b][c])	//저장된 값이 존재하면
		return dp[a][b][c];
	
	if (a < b && b < c)
		return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;

	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)	//종료 조건
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
	}
	return 0;
}
