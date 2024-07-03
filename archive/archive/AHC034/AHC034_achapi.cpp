#include <bits/stdc++.h>
using namespace std;
int print_d(char c, int d){
	if (d != 0){
		cout << c << d << endl;
		return 1;
	}
	return 0;
}
int main(){
	int N;
	cin >> N;
	// N = 20
	vector<vector<int>> h(N, vector<int>(N));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> h[i][j];
		}
	}
	int x = 0, y = 0;
	int v = 0;
	for (int k = 0; k < N / 2; k++){
		int l = 0, r = 1000000;
		while (l + 1 < r){
			auto _h = h;
			int mid = (l + r) / 2;
			int _x = 2 * k, _y = 0;
			int _v = 0;
			h[_x][_y] -= mid;
			_v += mid;
			for (int i = 0; i < 2; i++){
				for (int j = 0; j < N; j++){
					if (_x != 2 * k or _y != 0){
						if (h[_x][_y] > 0){
							int d = h[_x][_y];
							_v += d;
							h[_x][_y] = 0;
						}
						if (h[_x][_y] < 0) {
							int d = min(_v, -h[_x][_y]);
							_v -= d;
							h[_x][_y] += d;
						}
					}
					if (i % 2 == 0){
						if (_y + 1 < N){
							_y++;
						}
					} else {
						if (0 < _y){
							_y--;
						}
					}
				}
				if (i + 1 < 2){
					_x++;
				}
			}
			int cnt = 0;
			for (int i = k * 2; i < k * 2 + 2; i++){
				for (int j = 0; j < N; j++){
					if (h[i][j] == 0){
						cnt++;
					}
				}
			}
			if (cnt >= N * 2 - 1){
				r = mid;
			} else {
				l = mid;
			}
			h = _h;
		}
		print_d('+', r);
		h[x][y] -= r;
		v += r;
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < N; j++){
				if (x != 2 * k or y != 0){
					if (h[x][y] > 0){
						int d = h[x][y];
						print_d('+', d);
						v += d;
						h[x][y] = 0;
					}
					if (h[x][y] < 0) {
						int d = min(v, -h[x][y]);
						print_d('-', d);
						v -= d;
						h[x][y] += d;
					}
				}
				if (i % 2 == 0){
					if (y + 1 < N){
						y++;
						cout << 'R' << endl;
					}
				} else {
					if (0 < y){
						y--;
						cout << 'L' << endl;
					}
				}
			}
			if (i + 1 < 2){
				cout << 'D' << endl;
				x++;
			}
		}
		for (int i = 0; i < 1; i++){
			cout << 'U' << endl;
		}
		if (h[2 * k][0] < 0){
			int d = min(v, -h[2 * k][0]);
			print_d('-', d);
			v -= d;
			h[2 * k][0] += d;
		} else {
			int d = h[2 * k][0];
			print_d('+', d);
			v += d;
			h[2 * k][0] = 0;
		}
		for (int i = 0; i < 1; i++){
			cout << 'D' << endl;
		}
		if (x + 1 < N){
			x++;
			cout << 'D' << endl;
		}
	}
	for (int i = 0; i < N; i++){
		if (h[x][y] < 0){
			int d = min(v, -h[x][y]);
			print_d('-', d);
			v -= d;
			h[x][y] += d;
		}
		if (i + 1 < N){
			x--;
			cout << 'U' << endl;
		}
	}
}