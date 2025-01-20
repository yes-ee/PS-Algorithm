#include <iostream>
#include <set>

using namespace std;

int n, q;
set<int> s;

int main() {
    cin >> n >> q;

    int a, b;
    while (q--) {
        cin >> a >> b;

        while (1) {
            if (a > n) break;

            s.insert(a);
            a += b;
        }
    }

    cout << n - s.size();
    return 0;
}