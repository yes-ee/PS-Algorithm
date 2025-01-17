#include <iostream>

using namespace std;

int x, y;
int sum;

int main() {
    int a;

    for (int i =0; i<4;i++){
        cin >> a;
        sum += a;
    }

    x = sum / 60;
    y = sum % 60;

    cout << x << "\n" << y;

    return 0;
}