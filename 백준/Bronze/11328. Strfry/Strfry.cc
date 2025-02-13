#include <iostream>
#include <string>

using namespace std;

int n;
string a, b;
int arr[26];
int imp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        fill(arr, arr + 26, 0);
        imp = 0;
        cin >> a >> b;
        for (auto c : a) {
            arr[c - 'a']++;
        }
        for (auto c : b) {
            arr[c - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (arr[i]) {
                imp = 1;
                break;
            }
        }
        if (imp) cout << "Impossible\n";
        else cout << "Possible\n";
    }

    return 0;
}