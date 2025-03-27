// backtracking

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using namespace std;

string s;
int len;
int ans;
map<char, int> m;

void re(int cnt, char pre) {
    if (cnt == len) {
        ans++;
        return;
    }
    auto it = m.begin();
    while (it != m.end()) {
        char c = it->first;
        int cn = it->second;
        if (cn == 0 || c == pre) { // 같은 문자거나 다 사용했으면 패스
            it++;
            continue;
        }
        m[c]--;
        re(cnt + 1, c);
        m[c]++;
        it++;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    len = s.length();
    for (int i = 0; i < len; i++) {
        m[s[i]]++;
    }

    // map 돌면서 전체 조합 구하기
    for (auto nxt : m) {
        char c = nxt.first;
        char cn = nxt.second;
        m[c]--;
        re(1, c);
        m[c]++;
    }

    cout << ans;
    return 0;
}