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
bool cmp( int x , int y ){
    if( x % 2 == 0 ){
        if( y%2 == 0 ) return x > y ;
        else{
            return true ;
        }
    }
    else{
        if( y%2 == 0 ) return false ;
        else{
            return x > y ;
        }
    }
}
void solve(){
    int n ;cin>>n;
    int a[n] ;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    sort( a , a + n , cmp );
    int ans = 0 ;
    for(int i = 0 ; i < n; i++){
        for(int j = i + 1 ; j < n ;j++){
            if( gcd( a[i] , 2 * a[j] ) > 1 ){
                ans++;
            }
        }
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
