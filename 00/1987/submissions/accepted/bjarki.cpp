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

char arr[30];

stringstream res;
bool bt(int at, int used, bool started, bool equal) {
    if (at == -1) {
        return !equal;
    }

    rep(d,0,10) {
        if (equal && d < arr[at]) {
            continue;
        }
        int nused = used;
        if (!(!started && d == 0)) {
            if (nused & (1<<d)) continue;
            nused |= 1<<d;
        }
        if (bt(at-1, nused, started || d > 0, equal && d == arr[at])) {
            if (started || d > 0) res << d;
            return true;
        }
    }
    return false;
}

int main() {
    int ts;
    cin >> ts;
    rep(t,0,ts) {
        rep(i,0,30) arr[i] = 0;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        rep(i,0,size(s)) arr[i] = s[i] - '0';

        assert(bt(20, 0, false, true));
        s = res.str();
        reverse(s.begin(), s.end());
        cout << s << endl;
        res.clear();
        res.str("");
    }

    return 0;
}

