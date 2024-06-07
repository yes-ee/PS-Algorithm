#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


int n,t;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> t;

    while (n--) {
        ll s, i, c;

        cin >> s >> i >> c; // 시작, 간격, 대수

        for (ll j = 0; j < c; j++) {
            v.push_back(s);
            s += i;
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= t) {
            cout << v[i] - t;
            return 0;
        }
    }
    
    cout << -1;

    return 0;
}