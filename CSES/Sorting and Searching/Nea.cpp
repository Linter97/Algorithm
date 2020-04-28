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
	int n, a;
	cin >> n;
	vector<pii> v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		while (!v.empty() && v.back().first >= a) {
			v.pop_back();
		}
		if (v.empty()) cout << "0 ";
		else {
			cout << v.back().second << " ";
		}
		v.push_back({ a, i + 1 });
	}
}
