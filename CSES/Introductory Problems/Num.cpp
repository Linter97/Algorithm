#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int x, y, ma;
		cin >> x >> y;
		if (x > y) {
			if (x % 2 == 0) cout << (ll)x * x - y + 1;
			else cout << (ll)(x - 1) * (x - 1) + y;
		}
		else if (x < y) {
			if (y % 2 == 1) cout << (ll)y * y - x + 1;
			else cout << (ll)(y - 1) * (y - 1) + x;
		}
		else cout << (ll)x * x - x + 1;
		cout << "\n";
	}
}
