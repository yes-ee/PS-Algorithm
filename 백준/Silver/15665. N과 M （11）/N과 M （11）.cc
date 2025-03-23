#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using namespace std;

int n, m, nn;
vector<int> ans;
vector<int> arr;
set<int> s;

void print() {
    for (auto i : ans) cout << i << " ";
    cout << "\n";
}

void re(int cnt) {
    if (cnt == m) {
        print();
        return;
    }

    for (int i = 0; i < nn; i++) {
        ans.push_back(arr[i]);
        re(cnt + 1);
        ans.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }

    for (int i : s) arr.push_back(i);
    sort(arr.begin(), arr.end());
    nn = s.size();

    re(0);

    return 0;
}