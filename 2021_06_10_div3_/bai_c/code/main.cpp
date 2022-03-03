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
    int n ;cin>>n ;
    int l , r;cin>>l>>r;
    vector<int> a(n);
    for(int i = 0 ; i< n ; i++){
        cin>>a[i];
    }
    sort( a.begin() ,  a.end()  );
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        int x = lower_bound( a.begin() + i+1 , a.end() , l - a[i] ) - a.begin()  ;
        int y = upper_bound( a.begin() + i + 1  , a.end() , r - a[i] ) - a.begin();
        //debug( x );
        //debug( y );
        if( x > y  ) continue;
        ans += y - x ;
    }
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
