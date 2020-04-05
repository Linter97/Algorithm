#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll T[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> T[i];
	stack<int> st;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && T[st.top()] > T[i]) {
			ll h = T[st.top()];
			st.pop();
			ll w = i;
			if (!st.empty()) w = i - st.top() - 1;
			res = max(res, h * w);
		}
		st.push(i);
	}
	while (!st.empty()) {
		ll h = T[st.top()];
		st.pop();
		ll w = n;
		if (!st.empty()) w = n - st.top() - 1;
		res = max(res, h * w);
	}
	cout << res << "\n";
}
