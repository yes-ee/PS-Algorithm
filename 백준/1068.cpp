#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int par;
	int valid;
	vector<int> childs;
};

int n, p, d, cnt;
vector<Node> v;

void del(int idx) {
	if (v[idx].childs.empty())
		return;

	for (int c : v[idx].childs) {
		v[c].valid = 0;
		del(c);
		v[c].childs.clear();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		Node node;

		cin >> p;

		node.par = p;
		node.valid = 1;

		v.push_back(node);
	}

	for (int i = 0; i < n; i++) {
		if (v[i].par != -1) {
			int par_idx = v[i].par;
			v[par_idx].childs.push_back(i);
		}
	}

	cin >> d;

	del(d);
	v[d].valid = 0;

	for (int i = 0; i < n; i++) {
		if (v[i].valid && v[i].childs.empty()) {
			cnt++;
		}
	}

	int par_idx = v[d].par;

	if (v[par_idx].childs.size() == 1)
		cnt++;

	cout << cnt;

	return 0;
}