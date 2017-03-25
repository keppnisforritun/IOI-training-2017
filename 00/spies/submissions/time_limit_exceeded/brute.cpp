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

bool adj[5010][5010];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int k;
    scanf("%d", &k);

    memset(adj,0,sizeof(adj));
    rep(i,0,k) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        adj[a][b] = true;
    }

    rep(i,0,n) {
        rep(j,i+1,n) {
            int cnt = 0;
            rep(k,0,m) {
                if (adj[i][k] && adj[j][k]) {
                    cnt++;
                    if (cnt == 2) {
                        break;
                    }
                }
            }
            if (cnt == 2) {
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");

    return 0;
}

