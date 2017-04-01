#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    int left, right;
    Node()
    {
        this->val = 0;
        this->left = 0;
        this->right = 0;
    }
};

int main()
{
    int n;
    cin >> n;
    map<int, Node> m;
    set<int, greater<int> > s;
    for(int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        if(i == 0)
        {
            s.insert(v);
            m[0].left = v;
            m[v].val = v;
        }
        else
        {
            set<int>::iterator it = s.upper_bound(v);
            if(it == s.end())
            {
                cout << "NO" << endl;
                return 0;
            }
            else
            {
                s.insert(v);
                m[v].val = v;
                if(m[*it].left)
                {
                    m[*it].right = v;
                    s.erase(it);
                }
                else
                {
                    m[*it].left = v;
                }
            }
        }
    }

    cout << "YES" << endl;
    return 0;
}
