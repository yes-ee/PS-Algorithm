#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> v = {'a', 'e', 'i', 'o', 'u'};
vector<char> words; // 후보
vector<char> pwd; // 조합된 비밀번호
int ans;

int l, c;

void print() {
	for (int i = 0; i < pwd.size(); i++)
		cout << pwd[i];
	cout << "\n";
}

void dfs(int s, int cnt) {
	if (cnt == l) {
		int vc = 0;

		for (int i = 0; i < pwd.size(); i++) {
			if (find(v.begin(), v.end(), pwd[i]) != v.end())
				vc++;
		}

		if (vc >=1 && (l - vc) >= 2)
			print();
	}

	for (int i = s + 1; i < c; i++) {
		pwd.push_back(words[i]);
		dfs(i, cnt + 1);
		pwd.pop_back();
	}
}

int main() {
	cin >> l >> c;

	for (int i = 0; i < c; i++) {
		char a;
		cin >> a;
		words.push_back(a);
	}

	sort(words.begin(), words.end());

	for (int i = 0; i < c - 2; i++) {
		pwd.clear();
		pwd.push_back(words[i]);
		dfs(i, 1);
	}
}