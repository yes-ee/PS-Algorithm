#include <iostream>
#include <vector>

using namespace std;

int n, ans = 1e9;
vector<int> v[11];
int p[11];
int check[11];
int par[11];
int sum[11];

int find(int a) {
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}

void merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;

	par[b] = a;
	sum[a] += sum[b];
}

void cal() {
	int a = -1, b = -1;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		sum[i] = p[i];
	}

	for (int i = 1; i <= n; i++) {
		int color = check[i];

		for (int j : v[i]) {
			if (check[j] == color)
				merge(i, j);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (check[i]){
			a = i;
			break;
		}	
	}

	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
		{
			b = i;
			break;
		}
	}

	a = find(a);
	b = find(b);

	if (b == -1) return;

	for (int i = 1; i<= n; i++) {
		if (check[i]) {
			if (a != find(i))
				return;
		}
		else {
			if (b != find(i))
				return;
		}
	}

	ans = min(abs(sum[a] - sum[b]), ans);
}

void re(int idx) {
	cal();

	for (int i = idx; i <= n; i++) {
		check[i] = 1;
		re(i + 1);
		check[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> p[i];

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			v[i].push_back(b);
		}
	}

	re(1);

	if (ans == 1e9)
		cout << "-1";
	else
		cout << ans;

	return 0;
}