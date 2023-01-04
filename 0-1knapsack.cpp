#include <iostream>

using namespace std;

int w[101];	//물건의 무게
int v[101];	//물건의 가치
int p[101][100001];

int n, k;	//물건의 개수, 가방의 무게

int main(void)
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];	//각 물건의 무게와 가치를 입력받는다
	}
	
	//dp를 이용하여 배열 p의 값을 계산
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (w[i] > j)	//물건의 무게가 가방의 무게를 넘을 경우
				p[i][j] = p[i - 1][j];
			else	//물건의 무게가 가방 무게를 넘지 않는 경우
				p[i][j] = max(p[i - 1][j], p[i - 1][j - w[i]] + v[i]);
		}
	}

	cout << p[n][k];
	return (0);
}