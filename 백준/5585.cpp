#include <iostream>

using namespace std;

int money[6] = {500, 100, 50, 10, 5, 1};
int cnt, sum;

int main() {
    int input;
    cin >> input;
    sum = 1000 - input;

    for(int i = 0; i < 6; i++) {
        cnt += sum / money[i];
        sum %= money[i];
    }

    cout << cnt;
    return 0;
}