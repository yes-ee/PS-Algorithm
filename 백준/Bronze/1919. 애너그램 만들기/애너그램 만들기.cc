#include <iostream>
#include <string>

using namespace std;

string a, b;
int ac[26];
int bc[26];
int ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b;

    for (auto i : a) ac[i - 'a']++;
    for (auto i : b) bc[i - 'a']++;

    for (int i = 0; i < 26; i++) {
        ans += abs(ac[i] - bc[i]);
    }

    cout << ans;
    
    return 0;
}