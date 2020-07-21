#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[1001][1001];
int r, c;

string up() {
	string res = "";
	for (int i = 1; i < r; i++) {
		res += "U";
	}
	return res;
}
string down() {
	string res = "";
	for (int i = 1; i < r; i++) {
		res += "D";
	}
	return res;
}
string left() {
	string res = "";
	for (int i = 1; i < c; i++) {
		res += "L";
	}
	return res;
}
string right() {
	string res = "";
	for (int i = 1; i < c; i++) {
		res += "R";
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}
	string ans = "";
	if (r % 2 != 0 || c % 2 != 0) {
		if (r % 2 == 0) {
			// 아래쪽 끝, right, 위쪽 끝, right
			for (int i = 0; i < c / 2; i++) {
				ans += down();
				ans += "R";
				ans += up();
				ans += "R";
			}
			ans += down();
		}
		else {
			// 오른쪽 끝, down, 왼쪽 끝, down
			for (int i = 0; i < r / 2; i++) {
				ans += right();
				ans += "D";
				ans += left();
				ans += "D";
			}
			ans += right();
		}
	}
	else {
		// 행 + 열이 홀수인 칸 1개 제외 가능
		int mr = -1, mc = -1;
		int t = 2e9;
		// 지울 수 있는 제일 작은 칸을 찾음 
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if ((i + j) % 2 != 0) {
					if (a[i][j] < t) {
						t = a[i][j];
						mr = i;
						mc = j;
					}
				}
			}
		}
		for (int i = 0; i < mr / 2; i++) {
			ans += right();
			ans += "D";
			ans += left();
			ans += "D";
		}
		for (int i = 0; i < mc / 2; i++) {
			ans += "D";
			ans += "R";
			ans += "U";
			ans += "R";
		}
		if (mc % 2 > mr % 2) ans += "DR";
		else ans += "RD";
		for (int i = 0; i < (c - mc - 1) / 2; i++) {
			ans += "R";
			ans += "U";
			ans += "R";
			ans += "D";
		}
		for (int i = 0; i < (r - mr - 1) / 2; i++) {
			ans += "D";
			ans += left();
			ans += "D";
			ans += right();
		}
	}
	cout << ans << "\n";
}
