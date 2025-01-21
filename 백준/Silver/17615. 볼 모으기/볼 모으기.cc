#include <iostream>
#include <string>

using namespace std;

int n, ans;
string s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;

    int len = s.length();
    int chg = 0;
    char col = s[len - 1];
    for (int i = len - 2; i >= 0; i--) {
        // if color diff -> change
        if (col != s[i]) {
            chg++;
            if (col == 'B') col = 'R';
            else col = 'B';
        }
        if (chg >= 2) break;
    }

    // color not changed
    if (chg <= 1) {
        cout << 0;
        return 0;
    }

    col = s[len - 1];
    int st = len - 2;
    int f = 0;
    int sc = 0;
    while (st && (col == s[st])) st--;
    for (int i = st; i >= 0; i--) {
        if (s[i] != col) f++;
        else sc++;
    }

    ans = min(f, sc);

    col = s[0];
    st = 1;
    f = sc = 0;
    while (st < n && (col == s[st])) st++;
    for (int i = st; i < n; i++) {
        if (s[i] != col) f++;
        else sc++;
    }
    ans = min(ans, min(f, sc));

    cout << ans;

    return 0;
}