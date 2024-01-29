// union find
// 전체 합쳐서 루트 다른 거 개수 출력

#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt;
vector<char> v[1000];
int p[1000000];
int check[1000000];

void init()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[m * i + j] = m * i + j;
		}
	}
}

int find(int a)
{
	if (p[a] == a)
		return a;

	return p[a] = find(p[a]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
		return;

	p[a] = b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	if (n == 1 && m == 1)
	{
		cout << "1";
		return 0;
	}

	string s;
	init();

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			char c = s[j];
			int x = m * i + j;
			int nx = x;
			if (c == 'D')
			{
				nx += m;
			}
			else if (c == 'U')
			{
				nx -= m;
			}
			else if (c == 'L')
			{
				nx -= 1;
			}
			else
			{
				nx += 1;
			}
			merge(x, nx);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x = m * i + j;
			if (check[find(x)] == 0)
			{
				check[find(x)] = 1;
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}