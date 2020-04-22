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
		int a, b;
		cin >> a >> b;
		if (a < b) swap(a, b);
		if (a > b * 2) cout << "NO\n";
		else {
			a %= 3;
			b %= 3;
			if (a < b)swap(a, b);
			if ((a == 2 && b == 1) || (a == 0 && b == 0))cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
