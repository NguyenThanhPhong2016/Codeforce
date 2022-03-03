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
const int N = 262144 + 100;
int ans ;
string b ;
int x ;
int s[4*N];
void update( int u  ){
    while( u!=0 ){
        if( b[u] == '0' ) s[u] = s[2*u+1] ;
        else if( b[u] =='1' ) s[u] = s[2*u];
        else s[u] = s[2*u] + s[2*u + 1];
        u = u /2 ;
    }
}
void solve(){
    int k ; cin>>k ;
    x = (1<<k )- 1 ;
    string a ;cin>>a;
    a = " "+ a ;
    b  = a ;
    int dem = -1 ;
    int l = 1 ;
    int r = x  ;
    /*
    while( dem <= k-2 ){
        dem++;
        for(int i = 0 ; i < ( 1<<dem ) ; i++ ){
            //debug(r);
           // debug( a[r] );
            b[l] = a[r];
            c[r] = l ;
            l++;r--;
        }
    }
    */
    for(int i = 1 ; i <= x ; i++){
        b[i] = a[ x + 1 - i ];
    }
    for(int i = x + 1 ; i <= 2*x+2 ; i++){
        s[i] = 1;
    }
    for(int i  =x ; i>=1 ; i--){
        update( i );
    }
    int q ; cin>>q;
    for(int o = 0 ;o < q ; o++){
        int p; char d;cin>>p>>d;
        b[ x + 1 - p ] = d;
        update( x  + 1 - p );
        cout<<s[1]<<endl;
    }
}

signed main(){
    srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t =1 ;
    while(t--){
        solve();
    }
}
