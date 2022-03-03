#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define F first
#define S second
#define pii pair <int, int>
#define ull unsigned long long
#define int ll

using namespace std;
using namespace __gnu_pbds;

template < typename T >

using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 300010 * 5;
int t[N];

void upd(int v, int val)
{
    int h = v;
    t[v] = val;
    while (v != 1)
    {
        v /= 2;
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
    cout<<"in v : "<<h<<endl;
    for(int i = 0;i<=h;i++){
        cout<<i<<" : "<<t[i]<<endl;
    }

    return;
}



int get(int v,int a1, int a2, int b1, int b2)
{
    if (a1 >= b1 && a2 <= b2){
        cout<<"a1 : "<<a1<<endl;
        cout<<"a2 : "<<a2<<endl;
        cout<<"b1 : "<<b1<<endl;
        cout<<"b2 : "<<b2<<endl;
        cout<<"v : "<<v<<endl;
        return t[v];
    }
    if (a1 > b2 || b1 > a2) return -1e18;

    int mid = (a1 + a2) / 2;
    return max(get(v * 2, a1, mid, b1, b2), get(v * 2 + 1, mid + 1, a2, b1, b2));
}
int32_t main() {

#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif LOCAL

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector < int > h(n);
    vector < int > a(n);


    int k = 1;

    while (k < n) k *= 2;


    for (int i = 0; i < n; i++)
        cin >> h[i];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector < int > dp(n);

    for (int i = 0; i < n; i++) dp[i] = -1e18;

    for (int i = 0; i < k * 2; i++) t[i] = -1e18;
    dp[0] = a[0];
    upd(k, a[0]);
    deque < pii > q;

    q.push_front({h[0], 0});

    vector < int > p(n, -1);
    for (int i = 0; i < n; i++) p[i] = -1;
    for (int i = 1; i < n; i++)
    {
       while (q.size() > 0 && q.front().F > h[i])
        q.pop_front();

       if ((int)q.size() > 0)
       {
           p[i] = q[0].S;
       }

       q.push_front({h[i], i});
    }




    int mi = 0;


    for (int i = 1; i < n; i++)
    {
        if (h[mi] > h[i]) mi = i;
        cout<<"mi"<<mi<<endl;
        if (p[i] == -1)
        {
            int ma = get(1, 1, k, 1, i);
            cout<<"ma : "<<ma<<endl;
            ma = max(ma, 0ll);
            dp[i] = ma + a[i];
            cout<<"dp "<<i<<" : "<<dp[i]<<endl;
            cout<<"upd voi i = "<<i+k<<endl;
            upd(i + k, dp[i]);
        }
        else
        {
           int nom = p[i];

           int val = get(1, 1, k, nom + 1, i);
           cout<<"val : "<<val<<endl;
           cout<<"a "<<mi<<" : "<<a[mi]<<endl;
           dp[i] = max({ val + a[i], dp[nom]});
           cout<<"dp "<<i<<" : "<<dp[i]<<endl;
            cout<<"upd voi i = "<<i+k<<endl;
           upd(k + i, dp[i]);
        }
    }


    for(int i = 0 ;  i< n ; i++){
        cout<<"dp "<<i<<" :"<<dp[i]<<endl;
    }
   cout << dp[n - 1];

    return 0;
}
