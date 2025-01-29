#include <iostream>
#include <algorithm>

using namespace std;
using ld = long double;

int nx, ny;
ld w, half;
ld xis[1001];
ld yis[1001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (1) {
        cin >> nx >> ny >> w;
        if (nx == 0 && ny == 0 && w == 0.0) break;

        for (int i = 0; i < nx; i++) cin >> xis[i];
        for (int i = 0; i < ny; i++) cin >> yis[i];

        if (!nx || !ny) {
            cout << "NO\n";
            continue;
        }

        sort(xis, xis + nx);
        sort(yis, yis + ny);

        half = w / 2;
        ld st, ed;
        int fin = 0;
        st = xis[0] - half;
        ed = xis[0] + half;
        if (st > 0) {
            cout << "NO\n";
            continue;
        }

        for (int i = 1; i < nx; i++) {
            if (xis[i] - half > ed) {
                fin = 1;
                cout << "NO\n";
                break;
            }
            ed = xis[i] + half;
        }

        if (fin) continue;

        if (!fin && ed < 75) {
            cout << "NO\n";
            continue;
        }

        st = yis[0] - half;
        ed = yis[0] + half;
        if (st > 0) {
            cout << "NO\n";
            continue;
        }

        for (int i = 1; i < ny; i++) {
            if (yis[i] - half > ed) {
                fin = 1;
                cout << "NO\n";
                break;
            }
            ed = yis[i] + half;
        }

        if (fin) continue;

        if (!fin && ed < 100) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}