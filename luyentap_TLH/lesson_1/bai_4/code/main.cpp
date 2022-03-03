#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
bool cmp( ii a , ii b ){
    if( a.fi*b.se <= a.se*b.fi ){
        return true;
    }
    else return false;
}
void solve(){
    int n , k ; cin>>n>>k ;
    ii a[n];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i].fi;
    }
    for(int i = 0 ; i < n ; i++){
        cin>>a[i].se;
    }
    sort( a , a + n , cmp );
    int  h = __gcd( a[k-1].fi , a[k-1].se );
    cout<<a[k-1].fi/h<<" "<<a[k-1].se/h;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; t = 1;
    while(t--){
        solve();
    }
}
