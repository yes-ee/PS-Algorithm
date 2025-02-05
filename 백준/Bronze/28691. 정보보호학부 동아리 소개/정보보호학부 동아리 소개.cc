#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s == "M") cout << "MatKor";
    else if (s == "W") cout << "WiCys";
    else if (s == "C") cout << "CyKor";
    else if (s == "A") cout << "AlKor";
    else cout << "$clear";
    return 0;
}