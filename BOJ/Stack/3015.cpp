#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[500001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	stack<pll> st;
	ll res = 0;
	for(int i = 0; i < n; i++){
		ll cnt = 1;
		if(!st.empty()) {
			while (a[st.top().first] <= a[i]) {
				res += st.top().second;
				if (a[st.top().first] == a[i]) cnt = st.top().second + 1;
				st.pop();
				if (st.empty()) break;
			}
			if (!st.empty()) res++;
		}
		st.push({ i, cnt });
	}
	cout << res << "\n";
}
