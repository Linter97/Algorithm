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
	ll sum = 0;
	for (int i = 0; i < n - 1; i++) {
		int x;
		cin >> x;
		sum += x;
	}
	sum = (ll)n * (n + 1) / 2 - sum;
	cout << sum << "\n";
}
