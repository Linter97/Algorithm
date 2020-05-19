#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	stack<pii> st;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (!st.empty() && st.top().first > x) {
			auto s = st.top();
			st.pop();
			ll w = i;
			if (!st.empty()) w = i - st.top().second - 1;
			res = max(res, s.first * w);
		}
		st.push({ x, i });
	}
	while (!st.empty()) {
		auto s = st.top();
		st.pop();
		ll w = n;
		if (!st.empty()) w = n - st.top().second - 1;
		res = max(res, s.first * w);
	}
	cout << res << "\n";
}
