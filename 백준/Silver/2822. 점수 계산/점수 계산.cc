#include <iostream>
#include <algorithm>

using namespace std;
using pii=pair<int, int>;

vector<pii> v;
vector<int> ans;
int sum;

int main() {
    for (int i = 1; i <= 8; i++) {
        int a;
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end(), greater());
    for (int i = 0; i < 5; i++) {
        sum += v[i].first;
        ans.push_back(v[i].second);
    }
    cout << sum << "\n";
    sort(ans.begin(), ans.end());
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}