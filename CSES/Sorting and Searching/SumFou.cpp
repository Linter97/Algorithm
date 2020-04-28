#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pll a[1001];
vector<pair<ll, pll>> ta;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			ta.push_back({ a[i].first + a[j].first, {a[i].second, a[j].second} });
		}
	}
	sort(ta.begin(), ta.end());
	for (int i = 0; i < ta.size(); i++) {
		ll f = ta[i].first;
		int a1 = ta[i].second.first, a2 = ta[i].second.second;
		auto it = lower_bound(ta.begin() + i + 1, ta.end(), pair<ll, pll>{ x - f, { 0, 0 } });
		if (it != ta.end()) {
			if (f + it->first == x) {
				int a3 = it->second.first, a4 = it->second.second;
				if (a1 == a3 || a1 == a4 || a2 == a3 || a2 == a4) continue;
				else {
					cout << a1 << " " << a2 << " " << a3 << " " << a4 << "\n";
					return 0;
				}
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}
