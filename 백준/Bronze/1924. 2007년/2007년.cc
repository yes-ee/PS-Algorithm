#include <iostream>
#include <string>

using namespace std;

int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string arr[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int x, y, sum;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> x >> y;
    for (int i = 1; i < x ; i++) sum += day[i];
    sum += y;

    cout << arr[sum % 7];

    return 0;
}