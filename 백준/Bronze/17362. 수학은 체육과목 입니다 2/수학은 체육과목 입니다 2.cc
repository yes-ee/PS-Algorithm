#include <iostream>

using namespace std;

int n;

int main() {
	cin >> n;

	int num = n % 8;

	if (num == 0) num = 2;
	else if (num > 5) num = 10 - num;

	cout << num;

	return 0;
}