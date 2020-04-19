#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pii a[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
	sort(a, a + n);
	int here = a[0].first, res = 1;
	for (int i = 1; i < n; i++) {
		if (a[i].second >= here) {
			here = a[i].first;
			res++;
		}
	}
	cout << res << "\n";
}
