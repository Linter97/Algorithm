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
	ll sum = 0;
	int prev = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum > x) {
			sum -= a[prev++];
			sum -= a[i--];
		}
		else if (sum == x) {
			cnt++;
			sum -= a[prev++];
		}
	}
	cout << cnt << "\n";
}
