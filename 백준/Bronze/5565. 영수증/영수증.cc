#include <iostream>

using namespace std;

int sum;

int main() {
    cin >> sum;
    int a;
    for (int i = 0; i < 9; i++) {
        cin >> a;
        sum -= a;
    }

    cout << sum;

    return 0;
}