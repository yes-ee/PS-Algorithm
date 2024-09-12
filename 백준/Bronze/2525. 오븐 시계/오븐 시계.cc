#include <iostream>

#define MAX 1440

using namespace std;

int a, b, c;

int main() {
	cin >> a >> b >> c;

	int tm = a * 60 + b;

	tm += c;

	// 하루 지났을 때
	if (tm >= MAX) {
		tm -= MAX;
	}

	cout << tm / 60 << " " << tm % 60;

	return 0;
}