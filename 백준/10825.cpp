#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>

using namespace std;

int n;
string name;
int ko, en, math;
vector<tuple<string, int, int, int>> v;


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> name >> ko >> en >> math;
		v.push_back(make_tuple(name, ko, en, math));
	}

	sort(v.begin(), v.end(), [](tuple<string, int, int, int> a, tuple<string, int, int, int> b)
		 {
		if (get<1>(a) == get<1>(b)) {
			if (get<2>(a) == get<2>(b)) {
				if (get<3>(a) == get<3>(b)) {
					return get<0>(a) < get<0>(b);
				}
				return get<3>(a) > get<3>(b);
			}
			return get<2>(a) < get<2>(b);
		}
		return get<1>(a) > get<1>(b); });

	for (int i = 0; i < n; i++) {
		cout << get<0>(v[i]) << "\n";
	}

	return 0;
}