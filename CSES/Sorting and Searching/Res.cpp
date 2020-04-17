#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pii p[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
	sort(p, p + n);
	int here = 0;
	priority_queue<int> pq;
	int res = 0;
	for (int i = 0; i < n; i++) {
		here = p[i].first;
		while (!pq.empty() && -pq.top() < here) pq.pop();
		pq.push(-p[i].second);
		res = max(res, (int)pq.size());
	}
	cout << res << "\n";
}
