#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll t[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> t[i];
	sort(t, t + n);
	ll res = 0;
	for (int i = 0; i < n; i++) res += t[i];
	cout << max(res, 2 * t[n - 1]) << "\n";
}
