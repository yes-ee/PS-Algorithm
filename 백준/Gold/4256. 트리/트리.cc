#include <bits/stdc++.h>

using namespace std;

int n, t;
int pre[100001];
int in[100001];
// int post[100001];
int idx[100001];

void re(int in_st, int in_end, int pre_st, int pre_end)
{
	// get root node
	int root_idx = idx[pre[pre_st]];
	int left_size = root_idx - in_st;
	int right_size = in_end - root_idx;

	// left tree
	if (left_size)
		re(in_st, root_idx - 1, pre_st + 1, pre_st + left_size);
	// right tree
	if (right_size)
		re(root_idx + 1, in_end, pre_st + left_size + 1, pre_end);

	cout << pre[pre_st] << " ";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> pre[i];

		for (int i = 0; i < n; i++) {
			cin >> in[i];
			idx[in[i]] = i;
		}

		re(0, n - 1, 0, n - 1);
		cout << "\n";
	}
	return 0;
}