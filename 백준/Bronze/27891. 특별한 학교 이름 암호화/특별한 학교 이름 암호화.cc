#include <bits/stdc++.h>

using namespace std;

string s;
string words[4] = {"northlondo", "branksomeh", "koreainter", "stjohnsbur"};
string names[4] = {"NLCS", "BHA", "KIS", "SJA"};

int main() {
	cin >> s;

	for (int i = 0; i < 4; i++) {
		string word = words[i];
		for (int j = 1; j < 10; j++) {
			if (((26+ s[j] - s[j - 1]) % 26) != ((26+ word[j] - word[j - 1]) % 26)) break;
			if (j == 4) {
				cout << names[i];
				return 0;
			}
		}
	}
}