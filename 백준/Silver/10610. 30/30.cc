#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string n;
vector<char> v;
int sum, flag, zero;

int main() {
	cin >> n;
	for (int i = 0; i < n.length(); i++) {
		v.push_back(n[i]);
		if (n[i] == '0') zero = 1;
		sum += n[i] - '0';
	}

	if (!zero || sum % 3) {
		cout << "-1";
		return 0;
	}

	sort(v.begin(), v.end(), greater<char>());

	for (auto c : v)
		cout << c;
	
	return 0;
}