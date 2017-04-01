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
    cin.sync_with_stdio(false);
    int n, m, t;
    cin >> n >> m >> t;

    vii arr;
    rep(i,0,t) {
        int x,y;
        cin >> x >> y;
        arr.push_back(ii(x,y));
    }
    arr.push_back(ii(n,m));
    arr.push_back(ii(0,0));
    sort(arr.begin(), arr.end());

    int mx = 0;
    rep(start,0,size(arr)) {
        set<int> S;
        multiset<int> sizes;
        S.insert(0);
        S.insert(m);
        sizes.insert(m);
        rep(at,start+1,size(arr)) {
            int cur = arr[at].second,
                w = arr[at].first - arr[start].first;
            mx = max(mx, w * *sizes.rbegin());
            if (S.find(cur) != S.end())
                continue;
            set<int>::const_iterator it = S.insert(cur).first;
            it--;
            int a = *it;
            it++;
            it++;
            int b = *it;
            sizes.erase(sizes.find(b - a));
            sizes.insert(b - cur);
            sizes.insert(cur - a);
        }
    }
    cout << mx << endl;
    return 0;
}

