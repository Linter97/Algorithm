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
	deque<int> dq, dql, dqr;
	int res = 0;
	for (int i = 1; i <= n; i++) dq.push_back(i);
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		dql = dqr = dq;
		while (1) {
			if (dql.front() == x) {
				dql.pop_front();
				dq = dql;
				break;
			}
			else if (dqr.front() == x) {
				dqr.pop_front();
				dq = dqr;
				break;
			}
			dql.push_back(dql.front());
			dql.pop_front();
			dqr.push_front(dqr.back());
			dqr.pop_back();
			res++;
		}
	}
	cout << res << "\n";
}
