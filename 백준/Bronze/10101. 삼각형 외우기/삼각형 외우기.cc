#include <iostream>

using namespace std;

int a, b, c;
int sum;

int main() {
    cin >> a >> b >> c;
    sum = a + b + c;
    if (sum != 180) cout << "Error";
    else if (a == 60 && b == 60 && c == 60) cout << "Equilateral";
    else if (a == b || a == c || b == c) cout << "Isosceles";
    else cout << "Scalene";
    return 0;
}