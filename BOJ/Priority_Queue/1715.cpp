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
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(-x);
	}
	int res = 0;
	while (pq.size() != 1) {
		int a = -pq.top();
		pq.pop();
		int b = -pq.top();
		pq.pop();
		res += a + b;
		pq.push(-(a + b));
	}
	cout << res << "\n";
}
