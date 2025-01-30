#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n;
int sum;
vector<pii> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());

    int st = v[0].first;
    int ed = v[0].second;

    for (int i = 1; i < n; i++) {
        x = v[i].first;
        y = v[i].second;

        if (x <= ed) ed = max(ed, y);
        else {
            sum += (ed - st);
            st = x;
            ed = y;
        }
    }
    sum += (ed - st);

    cout << sum;

    return 0;
}