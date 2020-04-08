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
	int n, l;
	cin >> n >> l;
	deque<pii> dq;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		while (!dq.empty() && i - dq.front().second >= l) {
			dq.pop_front();
		}
		while (!dq.empty() && dq.back().first >= a) {
			dq.pop_back();
		}
		dq.push_back({ a, i });
		cout << dq.front().first << " ";
	}
}
