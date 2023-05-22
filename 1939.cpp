#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

typedef pair<int, int> P;
vector<P> v[MAX];

int n, m;

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;

		cin >> a >> b >> c;
		if (v[a].size() || v[a][0].first)
		v[a].push_back({c, b});
	}


}