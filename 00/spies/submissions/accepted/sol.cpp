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

vi adj[5010];
bool found[5010][5010];

int main() {
    memset(found,0,sizeof(found));
    int n,m,k;
    scanf("%d %d", &n, &m);
    scanf("%d", &k);
    rep(i,0,k) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
    }
    rep(i,0,n) {
        rep(a,0,size(adj[i])) {
            rep(b,a+1,size(adj[i])) {
                int x = adj[i][a],
                    y = adj[i][b];
                if (found[x][y]) {
                    printf("NO\n");
                    return 0;
                }
                found[x][y] = true;
                found[y][x] = true;
            }
        }
    }
    printf("YES\n");
    return 0;
}

