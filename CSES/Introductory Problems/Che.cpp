#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

char a[9][9];
int col[20], diag[20], diag2[20];
int cnt;
void solve(int y) {
	if (y == 8) {
		cnt++;
		return;
	}
	for (int x = 0; x < 8; x++) {
		if (col[x] || diag[x + y] || diag2[x - y + 7] || a[y][x] == '*') continue;
		col[x] = diag[x + y] = diag2[x - y + 7] = 1;
		solve(y + 1);
		col[x] = diag[x + y] = diag2[x - y + 7] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> a[i][j];
		}
	}
	solve(0);
	cout << cnt << "\n";
}
