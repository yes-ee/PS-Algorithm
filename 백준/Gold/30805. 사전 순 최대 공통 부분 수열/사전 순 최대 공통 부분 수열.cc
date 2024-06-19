#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> ans;
vector<int> a;
vector<int> b;
int ai, bi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--) {
		int in;
		cin >> in;
		a.push_back(in);
	}

	cin >> n;

	while (n--) {
		int in;
		cin >> in;
		b.push_back(in);
	}

	while (1) {
		int mx = -1;
		int ax, bx;

		for (int i = ai; i < a.size(); i++) {
			for (int j = bi; j < b.size(); j++) {
				// 제일 크면서 b에 존재
				if (a[i] > mx && a[i] == b[j]) {
					mx = a[i];
					ax = i + 1;
					bx = j + 1;
				}
			}
		}

		// 더이상 공통 수가 존재 x
		if (mx == -1)
			break;

		ans.push_back(mx);
		ai = ax;
		bi = bx;
	}

	cout << ans.size() << "\n";

	for (int i : ans)
		cout << i << " ";

	return 0;
}