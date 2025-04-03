#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using namespace std;

string s;
string ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;

    for (auto c : s) {
        if (c == toupper(c)) ans += tolower(c);
        else ans += toupper(c);
    }
    cout << ans;
    return 0;
}