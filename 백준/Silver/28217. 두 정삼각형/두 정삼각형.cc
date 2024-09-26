#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int n;
int a[10][10];
int b[10][10];

int na[10][10];
int nb[10][10];

void turn() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
		{
			na[n - 1 - i + j][n - 1 - i] = a[i][j];
		}
	}

	for(int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
		{
			a[i][j] = na[i][j];
		}
	}
}

void rev() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			na[i][i - j] = a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			a[i][j] = na[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	int in;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
		{
			cin >> in;
			a[i][j] = in;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> in;
			b[i][j] = in;
		}
	}

	// test all
	int ans = INF;
	
	// origin a
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (a[i][j] != b[i][j]) cnt++;
		}
	}
	ans = min(cnt, ans);

	// turn once
	turn();
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (a[i][j] != b[i][j])
				cnt++;
		}
	}
	ans = min(cnt, ans);

	// turn once
	turn();
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (a[i][j] != b[i][j])
				cnt++;
		}
	}
	ans = min(cnt, ans);

	turn();
	cnt = 0;
	rev();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (a[i][j] != b[i][j])
				cnt++;
		}
	}
	ans = min(cnt, ans);

	turn();
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (a[i][j] != b[i][j])
				cnt++;
		}
	}
	ans = min(cnt, ans);
	
	turn();
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (a[i][j] != b[i][j])
				cnt++;
		}
	}
	ans = min(cnt, ans);

	cout << ans;

	return 0;
}

