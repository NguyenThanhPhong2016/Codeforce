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
int x , y ,a , b ;
int solve1(){
    int ans = 0 ;
    while( x >= a && y >= b ){
        y = y - b ;
        x = x - a ;
        if( x > y ) swap( x ,y  );
        ans++;
    }
    return ans ;
}
int solve(){
    if( x > y ) swap( x ,y  );
    if( a > b ) swap( a , b);
    if( a== b ){
        return x/a;
    }
    int sum = a + b ;
    int h = x / sum ;
    x = x - h * sum ;
    y = y - h* sum ;
    int ans = 0 ;
    ans+= h*2 ;
    int l = y / ( b - a );
    l = min( l ,(int) ( y -x ) / ( 2 *(b -a ) ) );
    debug(x);debug( y );
    l = min( l , h );
    ans -= l ;
    debug(l);debug(ans);
    ans += min( ( y + l * a  ) / b , ( x + l * b) /a ) ;
    return ans;
}
signed main(){
    srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        x =( rand() % 20 )+ 1;
        y =( rand() % 10 ) + 1 ;
        a =( rand() % 4 )+ 1;
        b =( rand() % 5 )+1;
        cin>>x>>y>>a>>b ;
        if( x > y ) swap( x ,y  );
        if( a > b ) swap( a , b);
        int m = x ;
        int n = y ;
        int p = a ; int z = b ;
        int kq1 = solve1();
        x = m ; y = n ; a = p ; b = z ;
        int kq2 = solve();
        x = m ; y = n ; a = p ; b = z ;
        if( kq1 != kq2  ){
            debug( a );
            debug(b);
            debug(x);debug(y);
            debug(kq1) ;
            debug(kq2);
            break;
        }
    }
}
