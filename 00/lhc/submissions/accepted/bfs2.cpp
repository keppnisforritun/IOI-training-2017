#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = 2147483647;

vi adj[1001000];
int n;

ii furthest(int start) {
    vi dist(n,-1);
    dist[start] = 0;
    queue<int> Q;
    Q.push(start);
    int last = start;
    while (!Q.empty()) {
        int cur = Q.front();
        last = cur;
        Q.pop();
        iter(it,adj[cur]) {
            int nxt = *it;
            if (dist[nxt] == -1) {
                dist[nxt] = 1 + dist[cur];
                Q.push(nxt);
            }
        }
    }
    return ii(last, dist[last]);
}

int main() {
    cin >> n;
    rep(i,0,n-1) {
        int a,b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << furthest(furthest(0).first).second + 1 << endl;

    return 0;
}

