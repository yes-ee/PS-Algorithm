#include <bits/stdc++.h>
#define MAX 100

using namespace std;
int graph[MAX][MAX];
int busy[MAX][MAX];
int t[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int b, n, m;
	int cnt = 0;

	cin >> b >> n >> m;

	for (int i = 0; i < n; i++) {
		int r, c, t;
		cin >> r >> c >> t;
		graph[r][c] = t;
	}

	int time = m + 3 * b - 2;
	for (int i = 0; i < time; i++) {
		// 컨테이너 시간 별 세팅
		for (int j = 0; j < b-1; j++)
			graph[b - 1][j] = graph[b - 1][j + 1];
		for (int j = 0; j < b-1; j++)
			graph[b - 1 - j][b - 1] = graph[b - j - 2][b - 1];
		for (int j = 0; j < b-1; j++)
			graph[0][b - 1 - j] = graph[0][b - j - 2];


		if (i < m) {
			graph[0][0] = 1;
		}
		else
			graph[0][0] = 0;
			// 포장
			for (int j = 1; j < b - 1; j++)
			{
				for (int k = 0; k < b - 1; k++)
				{
					int check = 0;
					if (graph[j][k] && !busy[j][k])
					{
						if (j == 1)
						{
							if (k == b - 2)
							{
								if (graph[1][b - 1])
								{
									graph[1][b - 1] = 0;
									check = 1;
								}
								else if (graph[0][b - 2])
								{
									graph[0][b - 2] = 0;
									check = 1;
								}
							}
							else
							{
								if (graph[0][k])
								{
									graph[0][k] = 0;
									check = 1;
								}
							}
						}
						else if (j == b - 2)
						{
							if (k == b - 2)
							{
								if (graph[b - 1][b - 2])
								{
									graph[b - 1][b - 2] = 0;
									check = 1;
								}
								else if (graph[b - 2][b - 1])
								{
									graph[b - 2][b - 1] = 0;
									check = 1;
								}
							}
							else
							{
								if (graph[b - 1][k])
								{
									graph[b - 1][k] = 0;
									check = 1;
								}
							}
						}
						else if (k == b - 2 && j > 1 && j < b - 2)
						{
							if (graph[j][b - 1])
							{
								graph[j][b - 1] = 0;
								check = 1;
							}
						}
						if (check)
						{
							cnt++;
							busy[j][k] = 1;
							t[j][k] = graph[j][k];
						}
					}
					if (busy[j][k])
					{
						t[j][k]--;
						if (t[j][k] == 0)
							busy[j][k] = 0;
					}
				}
			}
	}
	cout << cnt;

	return 0;
}