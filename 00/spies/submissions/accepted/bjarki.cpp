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

vi L[5010],
   R[5010];

bool used[5010][5010];

int main() {
    int n,m;
    cin >> n >> m;
    int k;
    cin >> k;

    rep(i,0,k) {
        int x,y;
        cin >> x >> y;
        x--, y--;
        L[x].push_back(y);
        R[y].push_back(x);
    }

    memset(used,0,sizeof(used));
    rep(i,0,n) {
        iter(it,L[i]) {
            iter(jt,R[*it]) {
                if (i == *jt) continue;
                if (used[i][*jt]) {
                    cout << "NO" << endl;
                    return 0;
                }
                used[i][*jt] = true;
            }
        }
    }
    cout << "YES" << endl;

    return 0;
}

