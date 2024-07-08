#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct loc {
	long double x;
	long double y;
};

loc map[1001];
long long dis[1001][1001];

int n;
int x, y;
long long mdis = 9999999999999;
loc ma, mb;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> map[i].x;
		cin >> map[i].y;
	}

	for (int i = 0; i < n; i++) {
		loc fb;
		long fdis = 0;

		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			long cal;

			if (!dis[i][j]) {
				cal = pow(map[i].x - map[j].x, 2) + pow(map[i].y - map[j].y, 2);
				dis[i][j] = dis[j][i] = cal;
			} else {
				cal = dis[i][j];
			}

			// most far x, y
			if (cal > fdis) {
				fb = map[j];
				fdis = cal;
			}
		}

		// min distance
		if (mdis > fdis) {
			mdis = fdis;
			ma = map[i];
			mb = fb;
		}

	}

	cout << ma.x << " " << ma.y;

	return 0;
}