#include <iostream>

using namespace std;

int xh, xm, xs, yh, ym, ys;
int st, ed, bt;

int main() {
    for (int i = 0; i < 3; i++) {
        cin >> xh >> xm >> xs >> yh >> ym >> ys;
        st = xh * 3600 + xm * 60 + xs;
        ed = yh * 3600 + ym * 60 + ys;
        bt = ed - st;
        cout << bt / 3600 << " " << (bt % 3600) / 60 << " " << bt % 60 << "\n";
    }
}