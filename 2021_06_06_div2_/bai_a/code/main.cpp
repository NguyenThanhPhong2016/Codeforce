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
    int n ; cin>>n;
    int a[n];
    set<int> s;
    int dem2 = 0 ;
    for(int i = 0  ;  i < n ; i++){
        cin>>a[i];
        if( a[i] < 0 ) dem2 = 1;
        s.insert( a[i] );
    }
    if( dem2==1 ){
        cout<<"NO"<<endl;
        return ;
    }
    sort( a , a+ n  );
    int dem = 0 ;
    int dem1= 0 ;
    while( true){
        set<int > s1  = s ;
        dem++;
        auto x = s.end();
        for(int i = 0 ; i < dem ; i++){
            x--;
            if( x == s.begin() ) dem1 = 1;
        }
        //debug(*x) ;
        if( dem1 == 1) break;
        for(auto a : s){
            if( a == *x ) break;
            if( s.find( *x - a ) == s.end() ){
                s1.insert( *x - a );
                dem = 0 ;
            }
        }
        s = s1 ;
    }
    cout<<"YES"<<endl;
    cout<<s.size()<<endl;
    for(auto x : s ){
        cout<<x<<" ";
    }
    cout<<endl;
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
