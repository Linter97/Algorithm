#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll a[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	map<ll, ll> m;
	ll sum = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		if ((sum % n + n) % n == 0) cnt++;
		if (m.find((sum % n + n) % n) != m.end()) {
			cnt += m[(sum % n + n) % n];
		}
		m[(sum % n + n) % n]++;
	}
	cout << cnt << "\n";
}
