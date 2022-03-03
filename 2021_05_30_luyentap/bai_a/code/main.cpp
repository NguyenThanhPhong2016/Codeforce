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
int xuli( int x  ){
    int dem = 0 ;
    int y = 1 ;
    int ans = 0 ;
    while( x >>dem != 0 ){
        int h = x % ( y<<1 ) ;
        if( h >= y  ){
            ans = ans + ( ( ( h - y + 1 )%2)<<dem ) ;
        }
        dem++;
        y = y<<1;
    }
    //debug(ans);
    return ans;
}
void solve(){
    int a , b ;
    cin>>a>>b;
    if( a==b ){
        cout<<0<<endl;
        return ;
    }
    int d= xuli(a-1);
    int c = xuli(b);
    if( a%2 ==0 ) a++;
    if( b%2 == 0 ) b--;
    int z = ( ( b -a )/2 + 1 )%2 ;
    int ans = c^d;
    ans = ( ans /2  )* 2 + z;
    cout<<ans<<endl ;
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
