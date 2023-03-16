#include <iostream>
#define MAX 64
using namespace std;

int n;
int arr[MAX][MAX];
string s;

void recur(int n, int r, int c)
{
	char temp;

	if (n == 1)
	{
		temp = arr[r][c] + '0';
		s += temp;
		return;
	}

	int start = arr[r][c];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (start != arr[r + i][c + j])	//다 같은 색이 아니면
			{
				s = s + "(";
				for (int i = 0; i < 4; i++)
					recur(n / 2, r + (n / 2) * (i / 2), c + (n / 2) * (i % 2));
				s = s + ")";
				return;
			}
		}
	}

	temp = arr[r][c] + '0';
	s += temp;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string input;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = input[j] - '0';
		}
	}

	s = "";
	recur(n, 0, 0);
	cout << s;

	return 0;
}