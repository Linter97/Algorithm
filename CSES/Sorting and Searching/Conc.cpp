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
	int n, m;
	cin >> n >> m;
	multiset<int> ms;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ms.insert(-x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		auto it = ms.lower_bound(-x);
		if (it == ms.end()) cout << "-1\n";
		else {
			cout << -(*it) << "\n";
			ms.erase(it);
		}
	}
}
