#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector<int> v;
ll res = 2e9;

void solve(int idx, ll sum) {
	if (idx == n) {
		if(sum >= 0) res = min(res, sum);
		return;
	}
	solve(idx + 1, sum + v[idx]);
	solve(idx + 1, sum - v[idx]);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	solve(0, 0);
	cout << res << "\n";
}
