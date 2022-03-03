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
    int x , y ,a , b ;cin>>x>>y>>a>>b;
    if( x > y ) swap( x ,y  );
    if( a > b ) swap( a , b);
    if( a== b ){
        cout<<x/a<<endl;return;
    }
    int maxbt = x / a;
    int ans =min( maxbt , (int) (  y -x  ) / ( b -a) )  ;
    x = x - ans*a;
    y = y - ans*b;
    int sum = a + b ;
    int kq = x / ( a + b) ;
    ans += kq*2 ;
    x = x - kq*sum;
    y = y - kq*sum;
    if( x >= a && y >= b ) ans++;
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
