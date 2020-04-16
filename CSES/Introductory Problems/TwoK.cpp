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
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll a = pow(i, 2) * (pow(i, 2) - 1) / 2;
		ll b = 4 * (i - 1) * (i - 2);
		cout << a - b << "\n";
	}
}
