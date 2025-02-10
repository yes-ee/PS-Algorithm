// dfs
// bitmask

#include <iostream>
#include <string>

using namespace std;

int words[50];
int state;
int n, k, ans;
string s;


void dfs(int idx, int cnt) {
    if (cnt == k) {
        int rd = 0;
        // count readable words
        for (int i = 0; i < n; i++) {
            if ((state & words[i]) == words[i]) rd++;
        }
        ans = max(ans, rd);
        return;
    }

    for (int i = idx + 1; i < 26; i++) {
        if (state & (1 << i)) continue; // if exist
        state |= (1 << i);
        dfs(i, cnt + 1);
        state -= (1 << i);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    int base = 1 | (1 << ('c' - 'a')) | (1 << ('i' - 'a')) | (1 << ('t' - 'a')) | (1 << ('n' - 'a'));
    state = base;
    k -= 5;

    for (int i = 0; i < n; i++) {
        cin >> s;
        int word = base;

        for (auto c : s) {
            word |= (1 << (c - 'a'));
        }
        words[i] = word;
    }

    if (k < 0) {
        cout << 0;
        return 0;
    }

    dfs(-1, 0);
    cout << ans;

    return 0;
}