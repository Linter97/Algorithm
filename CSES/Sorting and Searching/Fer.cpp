#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int res = 0;
	for (int i = n - 1, p = 0; i >= p; i--) {
		if (a[i] + a[p] <= x) {
			res++;
			p++;
		}
		else res++;
	}
	cout << res << "\n";
}
