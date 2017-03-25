#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
template <class T> int size(const T &x) { return x.size(); }
const int INF = 2147483647;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

set<ll> res;
void check(ll x, ll bp1) {
    ll b = bp1-1;
    if (1 <= x && x < b && b > 1) {
        res.insert(b);
    }
}
ll rev(ll n, ll b) {
    ll res = 0;
    while (n) {
        res = res * b + (n % b);
        n /= b;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    for (ll d = 1; d*d <= n; d++) {
        if (n % d == 0) {
            check(d,n/d);
            check(n/d,d);
        }
        if (d > 1 && n == rev(n,d)) {
            res.insert(d);
        }
    }
    iter(it,res) {
        cout << *it << endl;
    }
    return 0;
}

