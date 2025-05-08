#include <bits/stdc++.h>

using namespace std;
using pii=pair<int, int>;
using ll=long long;

string s;
string sen;
string word = "UCPC";
int i = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    getline(cin, s);

    for (auto c : s) {
        if (c == word[i]) {
            i++;
        }
        if (i == 4) {
            cout << "I love UCPC";
            return 0;
        }
    }
    cout << "I hate UCPC";

    return 0;
}