#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	stack<int>st;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && st.top() <= a[i]) {
			int curr = st.top();
			st.pop();
			if (st.empty()) {
				res += a[i];
				break;
			}
			res += min(st.top(), a[i]);
		}
		st.push(a[i]);
	}
	while (st.size() != 1) {
		st.pop();
		res += st.top();
	}
	cout << res << "\n";
}
