#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int A[4001], B[4001], C[4001], D[4001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		A[i] = a, B[i] = b, C[i] = c, D[i] = d;
	}
	vector<int> v1, v2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v1.push_back(A[i] + B[j]);
			v2.push_back(C[i] + D[j]);
		}
	}
	sort(v2.begin(), v2.end());
	ll cnt = 0;
	for (int i = 0; i < n * n; i++) {
		cnt += upper_bound(v2.begin(), v2.end(), -v1[i]) - lower_bound(v2.begin(), v2.end(), -v1[i]);
	}
	cout << cnt << "\n";
}
