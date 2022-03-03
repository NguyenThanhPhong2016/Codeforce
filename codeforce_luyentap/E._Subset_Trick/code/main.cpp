#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
using namespace std;
ll n, q , minbt , maxbt ;
map< ll, ll > ss;
vector< ii > ss1;
vector<ll> temp;
void in(){
    cout<<maxbt - minbt<<endl;
}
int main()
{
    cin>>n>>q;
    maxbt = 0;
    for(ll i = 0,x ; i< n;i++){
        cin>>x;
        temp.push_back(x);
        ss.insert( make_pair( i,x ) ) ;
    }
    minbt = ss.begin()->second;
    cout<<minbt<<endl;
    ll dau =0;ll cuoi = 0;
    for( int i = 0 ; i < n-1 ; i++ ){
        dau += temp[i];
        cuoi += temp[n-i-1];
        ii x(dau,cuoi);
        ss1.push_back( {dau,cuoi} );
    }
    for(int i = 0;i<ss1.size() ; i++ ){
        cout<<ss1[i].first<<endl;
    }
    return 0;
}
