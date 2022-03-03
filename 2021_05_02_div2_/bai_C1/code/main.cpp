#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
//  sort(v.begin(), v.end(), greater<int>());
//
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

void solve(){
    int n , m ,x ; cin>>n>>m>>x;
    int a[n];
    int b[n];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    set< ii > ss;
    for(int i = 0 ; i < m ; i++){
        ss.insert( { 0 , i } );
    }
    for(int i = 0 ; i < n ; i++){
        auto x = *ss.begin();
        ss.erase( x );
        x.fi = x.fi +  a[i];
        ss.insert(x);
        b[i] = x.se ;
    }
    cout<<"YES"<<endl;
    for(int i =0 ; i< n;i++){
        cout<<b[i]+1<<" ";
    }
    cout<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
