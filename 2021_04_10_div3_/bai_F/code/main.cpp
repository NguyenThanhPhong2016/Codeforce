#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define pii  pair<int,int>
#define piii pair<int,ii>
#define pb push_back
using namespace std;
int cantren( int x , int y ){
    if( x % y == 0 ) return x/y;
    else return 1 + x/y ;
}
void solve(){
    int n , c ;cin>>n>>c;
    pii s[n+2] ;
    for(int i = 1 ; i <= n ; i++){
        cin>>s[i].fi;
    }
    for(int i = 1 ; i <= n -1 ; i++){
        cin>>s[i].se;
    }
    s[n].se = 0 ;
    pii s1[n+2];
    s1[1].fi = 0 ;
    s1[1].se = 0 ;
    for(int i = 2 ; i <= n ;i++){
        if( s[i-1].se < s1[i-1].se ){
            s1[i].fi = s1[i-1].fi +1 ;
            s1[i].se = s1[ i -1 ].se - s[ i -1 ].se ;
            continue;
        }
        int b = s[i-1].se - s1[i-1].se ;
        int a = b / s[i-1].fi ;
        if( a * s[i-1].fi != b ){
            a++;
        }
        a++;
        s1[i].fi = a + s1[i-1].fi;
        s1[i].se =   (a-1)*s[i-1].fi - b ;
    }
   // for(int i = 1 ;i <= n ;i++){
   //     cout<<s1[i].fi<<" "<<s1[i].se<<endl;
   // }
    int maxbt = 2e9 +10 ;
    for(int i = 1  ; i <= n ;i++){
        maxbt = min( maxbt , cantren( c - s1[i].se , s[i].fi ) + s1[i].fi );
    }
    cout<<maxbt<<endl;
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
