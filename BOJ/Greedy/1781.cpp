#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		pq.push(-v[i].second);
		while (pq.size() > v[i].first) pq.pop();
	}
	int res = 0;
	while (!pq.empty()) {
		res -= pq.top();
		pq.pop();
	}
	cout << res << "\n";
}
 
