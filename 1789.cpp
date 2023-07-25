#include <iostream>

using namespace std;

unsigned int s, i;

int main() {
    cin >> s;

    for (i = 1; i <= s; i++) {
        s -= i;
    }

    cout << i - 1;

    return 0;
}
