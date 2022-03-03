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
vector<int> p ;
const int maxbt = 31622 ;
int l[maxbt+1];
int uoc( int a  ){
    int uoca = 0 ;
    if( a==1 ) return 0 ;
    for(auto x : p){
        if( x*x > a ) break;
        while( a%x == 0 ){
            a= a/x;
            uoca++;
        }
    }
    if( a != 1 ) uoca++;
    return uoca;
}
void solve(){
    int a , b , k ; cin>>a>>b>>k;
    int minbt = 2 ;
    int maxbt = 2 ;
    if( a==1 && b ==1  ){
        cout<<"NO"<<endl;return;
    }
    else if( a == 1 || b ==1 ){
        minbt = 1 ;
    }
    else if( a != b && ( a% b == 0 || b % a ==0 ) ){
        minbt = 1 ;
    }
    else{
        minbt = 2 ;
    }
    maxbt = uoc( a ) + uoc( b);
    if( k>= minbt && k <= maxbt  ){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i = 2 ; i <= maxbt ; i++){
        if( l[i] == 0 ) p.pb( i );
        for(int j = i + i ; j <=maxbt ; j = j + i){
            l[j] = 1 ;
        }
    }
    int t;cin>>t;
    while(t--){
        solve();
    }
}
