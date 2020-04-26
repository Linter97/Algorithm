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
	int x, n;
	cin >> x >> n;
	set<pii> s;
	multiset<int>ms;
	s.insert({ 0, x });
	ms.insert(x);
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		auto it = --s.lower_bound({ p, -INF });
		pii a = *it;
		s.erase(it);
		s.insert({a.first, p});
		s.insert({ p, a.second });
		auto m = ms.find(a.second - a.first);
		if (m != ms.end()) ms.erase(m);
		ms.insert(p - a.first);
		ms.insert(a.second - p);
		cout << *--ms.end() <<" ";
	}
}
