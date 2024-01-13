// 그리디

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<long long> road;	//도로 길이
vector<long long> price;	//주유소별 가격
int cur_idx, cur_price;
long long sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		long long a;
		cin >> a;
		road.push_back(a);
	}

	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		price.push_back(a);
	}

	cur_price = price[0];
	cur_idx = 0;

	while (cur_idx < n - 1) {
		if (price[cur_idx] < cur_price) {
			cur_price = price[cur_idx];
		}
		
		sum += cur_price * road[cur_idx];
		cur_idx++;
	}

	cout << sum;

	return 0;
}