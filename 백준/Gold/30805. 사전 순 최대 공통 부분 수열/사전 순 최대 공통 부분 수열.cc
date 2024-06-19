#include <iostream>
#include <vector>

using namespace std;

int n;
int use[101];
vector<int> ans;
vector<int> a;
vector<int> b;
int ai, bi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--)
	{
		int in;
		cin >> in;
		a.push_back(in);
	}

	cin >> n;

	while (n--)
	{
		int in;
		cin >> in;
		b.push_back(in);
	}

	for (int j = 0; j < a.size(); j++) {
		int mx = -1;
		int mx_idx = -1;

		for (int i = ai; i < a.size(); i++) {
			if (!use[i] && mx < a[i]) {
				mx_idx = i;
				mx = a[i];
			}
		}

		for (int i = bi; i < b.size(); i++) {
			if (b[i] == a[mx_idx]) {
				ai = mx_idx + 1;
				bi = i + 1;
				ans.push_back(a[mx_idx]);
				break;
			}
		}

		use[mx_idx] = 1;
	}

	cout << ans.size() << "\n";

	for (int i : ans)
		cout << i << " ";

	return 0;
}