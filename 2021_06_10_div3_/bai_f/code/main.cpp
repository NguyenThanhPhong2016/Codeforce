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
int s[100];
int xuli( int x){
    int ans = 0;
    int dem  = 0 ;
    while( x!=0 ){
        dem++;
        int h = x % 10 ;
        x = x/ 10 ;
        ans+= h*s[dem];
    }
    return ans ;
}
void solve(){
    int l , r ;cin>>l>>r;
    cout<<xuli( r ) - xuli( l )<<endl;

}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i = 1 ; i < 12 ; i++){
        s[i] = s[i-1]*10 + 1 ;
    }
    int t;cin>>t;
    while(t--){
        solve();
    }
}
