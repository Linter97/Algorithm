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
	int t, n;
	cin >> t >> n;
	deque<pii> dq, dq2;
	ll res = 0, l = 0;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		while (!dq.empty() && dq.back().first >= x) dq.pop_back();
		while (!dq2.empty() && dq2.back().first <= x) dq2.pop_back();
		dq.push_back({ x, i });
		dq2.push_back({ x, i });
		while (abs(dq.front().first - dq2.front().first) > t) {
			if (dq.front().second < dq2.front().second) {
				l = dq.front().second;
				dq.pop_front();
			}
			else {
				l = dq2.front().second;
				dq2.pop_front();
			}
		}
		res = max(res, i - l);
	}
	cout << res << "\n";
}
