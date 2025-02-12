#include <iostream>

using namespace std;

int b, d;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a;
    for (int i = 0; i < 3; i++) {
        b = d = 0;
        for (int j = 0; j < 4; j++) {
            cin >> a;
            if (a) d++;
            else b++;
        }
        if (d == 4) cout << "E";
        else if (b == 4) cout << "D";
        else if (b == 3) cout << "C";
        else if (b == 2) cout << "B";
        else if (b == 1) cout << "A";
        cout << "\n";
    }
    return 0;
}