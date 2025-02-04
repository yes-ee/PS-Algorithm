#include <iostream>

using namespace std;

int a, b, c, d, e;
int tm;

int main() {
    cin >> a >> b >> c >> d >> e;

    if (a < 0) {
        tm += c * (-a);
        a = 0;
    }
    if (a == 0) {
        tm += d;
    }
    tm += (b - a) * e;
    cout << tm;
    return 0;
}