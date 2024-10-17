#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int score[4];
double a;
int t;

int main()
{
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);

	for (int i = 0; i < 4; i++) {
		cin >> a;
		score[i] = round(a * 100);
		// cout << score[i] << " ";
	}

	cin >> a;

	t = round(a * 100);

	// cout << t << endl;

	sort(score, score + 4);


	if (score[1] + score[2] + score[3] <= 3 * t)
	{
		cout << "infinite";
		return 0;
	}

	if (score[0] + score[1] + score[2] > 3 * t) {
		cout << "impossible";
		return 0;
	}


	printf("%.2f", (3 * t - (score[1] + score[2])) / 100.00);

	return 0;

}