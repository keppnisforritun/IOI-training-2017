#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = 1000000000;

vi adj[1001000];
int mem1[1001000],
    mem2[1001000];

int height(int at, int par) {
    if (mem2[at] != -1)
        return mem2[at];
    int res = 0;
    iter(it,adj[at]) {
        if (*it == par) continue;
        res = max(res, 1 + height(*it, at));
    }
    return mem2[at] = res;
}

int dp(int at, int par, int up) {
    if (mem1[at] != -1) return mem1[at];
    int mx = height(at, par) + up;
    int h1 = -INF,
        h2 = -INF;
    iter(it,adj[at]) {
        if (*it == par) continue;
        int cur = height(*it, at);
        if (cur > h2) h2 = cur;
        if (h2 > h1) swap(h1,h2);
    }
    mx = max(mx, h1 + h2 + 2);
    iter(it,adj[at]) {
        if (*it == par) continue;
        int cur = height(*it, at),
            other = h1;
        if (cur == other) other = h2;
        mx = max(mx, dp(*it, at, max(up+1, 2 + other)));
    }
    return mem1[at] = mx;
}

int main() {
    memset(mem1,-1,sizeof(mem1));
    memset(mem2,-1,sizeof(mem2));

    int n;
    cin >> n;
    rep(i,0,n-1) {
        int a,b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << dp(0,-1,0) + 1 << endl;

    return 0;
}

