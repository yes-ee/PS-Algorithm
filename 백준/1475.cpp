#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
int arr[9];

int main() {
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '6' || s[i] == '9') {
			arr[6]++;
		}
		else
			arr[s[i] - '0']++;
	}

	int six = (arr[6] + 1) / 2;
	arr[6] = six;
	int m = * (max_element(begin(arr), end(arr)));

	cout << m;

	return 0;
}