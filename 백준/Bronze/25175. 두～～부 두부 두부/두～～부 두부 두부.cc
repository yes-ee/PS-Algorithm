#include <iostream>

using namespace std;

int n, m, k;

int main() {
    cin >> n >> m >> k;

    int ret = (m + (k - 3) % n + n) % n;

    cout << (ret == 0 ? n : ret);

    return 0;
}