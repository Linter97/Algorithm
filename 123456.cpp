#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cnt[300001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	queue<int> q;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		while (!q.empty() && q.size() > k) {
			cnt[q.front()]--;
			res += cnt[q.front()];
			q.pop();
		}
		cnt[s.length()]++;
		q.push(s.length());
	}
	while (!q.empty()) {
		cnt[q.front()]--;
		res += cnt[q.front()];
		q.pop();
	}
	cout << res << "\n";
}