#include <iostream>

using namespace std;

int l;
int arr[8] = {9, 99, 989, 9889, 97679, 976679, 9643469, 96433469};

int main() {
    cin >> l;

    if (l > 8) cout << "-1";
    else cout << arr[l - 1];

    return 0;
}
