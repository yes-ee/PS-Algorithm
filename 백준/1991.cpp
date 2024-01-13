#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> p;
p arr[26];

void pre(int parent) {
	if (parent == '.')
		return;
	cout << (char)parent;
	pre(arr[parent - 'A'].first);
	pre(arr[parent - 'A'].second);
}

void in(int parent) {
	if (parent == '.')
		return;
	in(arr[parent - 'A'].first);
	cout << (char)parent;
	in(arr[parent - 'A'].second);
}

void post(int parent) {
	if (parent == '.')
		return;
	post(arr[parent - 'A'].first);
	post(arr[parent - 'A'].second);
	cout << (char)parent;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		char a, b, c;
		cin >> a >> b >> c;
		arr[a - 'A'] = {b, c};
	}

	pre('A');
	cout << "\n";
	in('A');
	cout << "\n";
	post('A');

	return 0;
}