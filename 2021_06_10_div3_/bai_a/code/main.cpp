#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define endl "\n"
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
using namespace std;
//  sort(v.begin(), v.end(), greater<int>());
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

void solve(){
    int n ; cin>>n;
    int a[n];
    ii minb= {101 , 0 };
    ii maxb = {1 , 0} ;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
        if( minb.fi > a[i] ){
            minb.fi = a[i];
            minb.se = i ;
        }
        if( maxb.fi < a[i] ){
            maxb.fi = a[i];
            maxb.se = i ;
        }
    }
    int ans = 100;
    int x = min( minb.se , maxb.se );
    int y = max( maxb.se , minb.se );

    ans = min( ans , x  + 1+ n - y );

    ans = min( ans , y +1 );

    ans = min( ans , n - x );
    cout<<ans<<endl;
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
