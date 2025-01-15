#include <iostream>
#include <string>

using namespace std;

string s;
int ans;

bool isTime(int num) {
    if (num <= 0 || num > 12) return false;
    return true;
}

bool isMinSec(int num) {
    if (num < 0 || num > 59) return false;
    return true;
}

int main() {
    cin >> s;
    int a = stoi(s.substr(0, 2));
    int b = stoi(s.substr(3, 2));
    int c = stoi(s.substr(6, 2));

    if (isTime(a)) {
        if (isMinSec(b) && isMinSec(c)) ans += 2;
    }
    if (isTime(b)) {
        if (isMinSec(a) && isMinSec(c)) ans += 2;
    }
    if (isTime(c)) {
        if (isMinSec(a) && isMinSec(b)) ans += 2;
    }

    cout << ans;
    return 0;
}