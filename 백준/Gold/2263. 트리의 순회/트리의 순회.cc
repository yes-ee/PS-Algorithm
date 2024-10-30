#include <bits/stdc++.h>

using namespace std;

int n;
int in[100001];
int post[100001];
int idx[100001];

void re(int in_st, int in_end, int post_st, int post_end) {
	// get root node
	int root_idx = idx[post[post_end]];
	int left_size = root_idx - in_st;
	int right_size = in_end - root_idx;

	cout << post[post_end] << " ";

	// left tree
	if (left_size)
		re(in_st, root_idx - 1, post_st, post_st + left_size - 1);
	// right tree
	if (right_size)
		re(root_idx + 1, in_end, post_st + left_size, post_end - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> in[i];
		idx[in[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}

	re(0, n - 1, 0, n - 1);

	return 0;
}