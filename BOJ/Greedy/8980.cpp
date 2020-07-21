#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[2001];
int comp(pair<pii, int> i, pair<pii, int>j) {
	if (i.first.second == j.first.second) return i.first.first < j.first.first;
	return i.first.second < j.first.second;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, c, m;
	cin >> n >> c;
	cin >> m;
	vector<pair<pii, int>> v(m);
	for (int i = 0; i < m; i++) cin >> v[i].first.first >> v[i].first.second >> v[i].second;
	sort(v.begin(), v.end(), comp);
	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		int x = 0;
		for (int j = v[i].first.first; j < v[i].first.second; j++) x = max(x, a[j]);
		int left = min(v[i].second, c - x);
		res += left;
		for (int j = v[i].first.first; j < v[i].first.second; j++) a[j] += left;
	}
	cout << res << "\n";
}
 
