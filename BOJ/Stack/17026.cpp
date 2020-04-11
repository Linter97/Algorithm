#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pii a[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[i].first = x - y;
		a[i].second = x + y;
	}
	sort(a, a + n);
	stack<pii> st;
	for (int i = 0; i < n; i++) {
		if (st.empty()) st.push({a[i].first, a[i].second});
		else {
			if (st.top().first == a[i].first) {
				st.pop();
				st.push({ a[i].first, a[i].second });
			}
			else if (st.top().second < a[i].second) st.push({ a[i].first, a[i].second });
		}
	}
	cout << st.size() << "\n";
}
