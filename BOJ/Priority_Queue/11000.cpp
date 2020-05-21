#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pii a[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	priority_queue<int>pq;
	for (int i = 0; i < n; i++) {
		if (!pq.empty() && -pq.top() <= a[i].first) {
			pq.pop();
		}
		pq.push(-a[i].second);
	}
	cout << pq.size() << "\n";
}
