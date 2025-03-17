#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#define MAX 10

using namespace std;

int n, ret;
string words[MAX];
int cnt[26];

void countAlphabet(string s) {
	int len = s.length();
	int mul = 1;

	for (int i = len - 1; i >= 0; i--) {
		cnt[s[i] - 'A'] += mul;
		mul *= 10;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> words[i];
		countAlphabet(words[i]);
	}

	sort(cnt, cnt + 26, greater<>());

	int num = 9;
	for (int i = 0; i < 10; i++) {
		ret += cnt[i] * num;
		num--;
	}

	cout << ret;

	return 0;
}
