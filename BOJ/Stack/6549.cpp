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
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		stack<pll> st;
		ll res = 0;
		for (int i = 0; i < n; i++) {
			int h;
			cin >> h;
			while (!st.empty() && st.top().first > h) {
				pll pi = st.top();
				st.pop();
				ll w = i;
				if (!st.empty()) w = i - st.top().second - 1;
				res = max(res, pi.first * w);
			}
			st.push({ h, i });
		}
		while (!st.empty()) {
			pll pi = st.top();
			st.pop();
			ll w = n;
			if (!st.empty()) w = n - st.top().second - 1;
			res = max(res, pi.first * w);
		}
		cout << res << "\n";
	}
}
