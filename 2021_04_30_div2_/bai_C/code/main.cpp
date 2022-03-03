#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
//  sort(v.begin(), v.end(), greater<int>());

const int N = 2e5 + 10 ;
vector< ii > ss[N];
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    int n ; cin>>n;
    int a[n] ;
    int b[n] ;
    for(int i = 0 ; i < n ; i++ ){
        cin>>a[i];
    }
    for(int i = 0 ; i < n ; i++ ){
        cin>>b[i];
    }
    for(int i = 0 ; i < n ; i++ ){
        ss[ a[i] ].pb( { b[i] , 0 } );
    }
    int maxbt = 0;
    vector<int> ds ;
    for(int i = 1  ; i <= n ; i++){
        if( ss[i].size()!=0 ){
            maxbt = max( maxbt ,(int) ss[i].size() ) ;
            ds.pb( i );
            sort( ss[i].begin() , ss[i].end() );
            ss[i][0].se = ss[i][0].fi ;
            for( int j = 1 ; j < ss[i].size() ; j++ ){
                ss[i][j].se = ss[i][j].fi + ss[i][j-1].se ;
            }
        }
    }
    vector<int> ds1;
    for(int k = 1; k <= n ; k++){
        //cout<<"k : "<<k<<endl;
        if( k > maxbt ){
            cout<<0<<" ";
            continue;
        }
        int ans = 0;
        for( auto i : ds ){
            //cout<<" i:"<<i<<endl;
            int n1 = ss[i].size();
            if( n1 > k ){
                ds1.pb( i );
            }
            int h = n1 % k ;
            if( h ==0 ){
                ans += ss[i][n1-1].se;
            }
            else{
                ans += ss[i][n1 -1 ].se - ss[i][h-1].se;
            }
            //cout<<i<<"  ans : "<<ans<<endl;
        }
        cout<<ans<<" ";
        ds.clear();
        for(auto x : ds1) ds.pb(x);
        ds1.clear();
    }
    for(int i = 0; i <= n ;i++){
        ss[i].clear() ;
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
