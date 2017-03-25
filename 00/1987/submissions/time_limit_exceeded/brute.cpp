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

bool dis(int x) {
    int cur = 0;
    while (x) {
        int d = x % 10;
        if (cur & (1<<d)) return false;
        cur |= 1<<d;
        x /= 10;
    }
    return true;
}

int main() {
    int ts;
    cin >> ts;
    rep(t,0,ts) {
        int n;
        cin >> n;
        while (!dis(++n)) ;
        cout << n << endl;
    }

    return 0;
}

