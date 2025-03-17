#include <bits/stdc++.h>

using namespace std;

int arr[50];
int n;
int r;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 50; i++) {
        cin >> arr[i];
    }
    cin >> n;
    for (int i = 0; i < 50; i++) {
        if (arr[i] == n) {
            r = i + 1;
            break;
        }
    }

    if (r <= 5) cout << "A+";
    else if (r <= 15) cout << "A0";
    else if (r <= 30) cout << "B+";
    else if (r <= 35) cout << "B0";
    else if (r <= 45) cout << "C+";
    else if (r <= 48) cout << "C0";
    else cout << "F";
    return 0;
}