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
//
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
const int mod = 1e9 + 7 ;
int power( int a , int b ){
    //cout<<b<<endl;
    if( b== 1 ) return a ;
    int c = b/2 ;
    c = power( a , c ) % mod;
    c = ( c*c ) % mod ;
    if( b % 2 ==1  ) c = (c * a )%mod ;
    return c ;
}
void solve(){
    int n ; cin>>n ;
    if( n == 1  ){
        cout<<1<<endl;
        return ;
    }
    cout<<power( 3 , n - 1  )<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; t= 1 ;
    while(t--){
        solve();
    }
}
