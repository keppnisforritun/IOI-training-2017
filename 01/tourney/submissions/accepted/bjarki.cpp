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

ii best(ii a, ii b) {
    assert(a.first != b.first);
    if (a.first > b.first) {
        return a;
    } else {
        return b;
    }
}
ii ans[21][1<<20];
int n;
void update(int i, int x) {
    ans[n][i] = ii(x,i);
    for (int h = n-1; h >= 0; h--) {
        i = i / 2;
        ans[h][i] = best(ans[h+1][2*i], ans[h+1][2*i+1]);
    }
}

int main() {
    int m;
    cin >> n >> m;

    rep(i,0,(1<<n)) {
        int x;
        cin >> x;
        update(i,x);
    }

    rep(i,0,m) {
        char op;
        cin >> op;

        if (op == 'W') {
            cout << ans[0][0].second + 1 << endl;
        } else if (op == 'R') {
            int i, x;
            cin >> i >> x;
            i--;
            update(i,x);
        } else if (op == 'S') {

            int x;
            cin >> x;
            x--;
            int orig = x;
            int w = 0;
            for (int i = n; i >= 0; i--) {
                if (ans[i][x].second == orig) w++;
                x = x / 2;
            }
            cout << w-1 << endl;

        } else {
            assert(false);
        }
    }

    return 0;
}

