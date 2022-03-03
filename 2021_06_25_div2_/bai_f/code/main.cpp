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
const int mod = 1e9 + 7 ;
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int m = 15 ;
    int n ;cin>>n ;
    int c[n+1];
    for(int i = 1 ; i<= n ; i++){
        cin>>c[i];
        c[i] ;
    }
    int b[n];
    for(int i = 1 ; i < n ; i++){
        cin>>b[i];
        if( i<=m ) b[i] <<= (m-i) ;
    }
    int q ;cin>>q ;
    int x ; cin>>x ; x <<= m ;
    int s[n+1] ;
    s[n] = c[ n ];
    for(int i = n - 2 ; i >= 0 ; i-- ){
        s[i] = s[i+1] * c[i];
        s[i] %= mod ;
    }
    int sum = x ;
    for(int o = 1 ; i <= m ; i++){
        sum += b[i] ;
        int ans =
    }
}
