#include <iostream>
#include <string>
#include <algorithm>
#define MAX 200000
using namespace std;

int alpha[MAX][26];
int q, l, r, idx;
char a;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s >> q;

	idx = s[0] - 'a';
	alpha[0][idx]++;

	for (int i = 1; i < s.length(); i++)
	{
		copy_n(alpha[i - 1], 26, alpha[i]);
		idx = s[i] - 'a';
		alpha[i][idx]++;
	}

		while (q--)
		{
			cin >> a >> l >> r;
			if (l == 0)
				cout << alpha[r][a - 'a'] << "\n";
			else
				cout << alpha[r][a - 'a'] - alpha[l - 1][a - 'a'] << "\n";
		}
}
