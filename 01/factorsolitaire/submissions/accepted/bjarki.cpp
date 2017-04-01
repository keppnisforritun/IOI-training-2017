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

int main() {
    int n;
    cin >> n;

    vector<vi> divs(n+1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            divs[j].push_back(i);
        }
    }

    int *dp = new int[n+1];
    rep(i,0,n+1) dp[i] = INF;
    dp[1] = 0;

    // n
    // c = a * b
    // borga b
    // n = c + a

    // for (int ca = 2; ca <= n; ca++) {
    //     for (int a = 1; a < ca; a++) {
    //         int c = ca - a;
    //         if (c % a == 0) {
    //             int b = c / a;
    //             dp[ca] = min(dp[ca], b + dp[c]);
    //         }
    //     }
    // }

    for (int c = 1; c <= n; c++) {
        iter(it,divs[c]) {
            int a = *it;
            int ca = c + a;
            int b = c / a;
            if (ca <= n) {
                dp[ca] = min(dp[ca], b + dp[c]);
            }
        }
    }
    cout << dp[n] << endl;

    return 0;
}

