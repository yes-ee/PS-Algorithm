#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

string s, t;
string na, nb;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;

    int la = s.length();
    int lb = t.length();
    int _lcm = lcm(la, lb);

    for (int i = 0; i < _lcm / la;i++) na += s;
    for (int i = 0; i < _lcm / lb;i++) nb += t;

    for (int i = 0; i < na.length();i++) {
        if (na[i] != nb[i]) {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
    return 0;
}