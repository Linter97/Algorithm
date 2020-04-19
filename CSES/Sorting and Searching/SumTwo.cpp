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
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a, a + n);
	int sum = 0;
	for (int i = 0, l = n - 1; i < n; i++) {
		if (i == l) break;
		sum = a[i].first + a[l].first;
		if (sum < x) continue;
		else if (sum > x) {
			l--;
			i--;
		}
		else {
			cout << a[i].second << " " << a[l].second << "\n";
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
}
