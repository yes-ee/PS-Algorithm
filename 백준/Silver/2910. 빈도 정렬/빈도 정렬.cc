#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n, c;
map<int, int> mp; // 숫자, 횟수
map<int, int> lo; // 숫자, 처음 등장 위치
vector<tuple<int, int, int>> v; // 횟수, 위치, 숫자

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> c;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        mp[a]++;
        if (mp[a] == 1) lo[a] = i;
    }

    for (auto num : mp) {
        v.push_back({num.second, -lo[num.first], num.first});
    }
    sort(v.begin(), v.end(), greater());
    for (auto num : v) {
        int cnt, lo, n;
        tie(cnt, lo, n) = num;
        for (int j = 0; j < cnt; j++) {
            cout << n << " ";
        }
    }
    return 0;
}