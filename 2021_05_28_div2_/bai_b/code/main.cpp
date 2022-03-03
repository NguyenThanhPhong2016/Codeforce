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
int const N = 1e4 ;
int b[N];
void solve(){
    int n ; cin>>n ;
    if( n >= 1110 ){
        cout<<"YES"<<endl;
    }
    else{
        if( b[n] == 0 ) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    b[0] =1;
    for(int i = 0 ; i < 1400 ; i++){
        if( b[i] ==1 ){
            b[i+11] = 1;
            b[i+111] =1 ;
        }
    }
    int t;cin>>t;
    while(t--){
        solve();
    }
}
