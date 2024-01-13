#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long k, ans, temp;
string input;
vector<long long> p;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input.length() <= 13)
			p.push_back(stoll(input));
	}
	cin >> k;
	sort(p.begin(), p.end());
	for (int i = 0; i < p.size(); i++)
	{
		temp = k;
		while (temp)
		{
			temp /= p[i];
			ans += temp;
		}
	}
	cout << ans;
	return 0;
}