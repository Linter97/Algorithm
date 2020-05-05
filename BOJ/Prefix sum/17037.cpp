#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++) {
			a[j][y1]++;
			a[j][y2]--;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			if (a[i][j] == k) cnt++;
			a[i][j + 1] += a[i][j];
		}
	}
	cout << cnt << "\n";
}
