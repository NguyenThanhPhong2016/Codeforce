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
const int N = 1e3 + 10  ;
int a[N];
set< pair< string , int > > ans ;
string ans1 ;
int sl = 0;
void in(int k , string value ){
    if( k ==1 ){
        ans1 = ans1 + value;
        cout<<"sss1 : "<<ans1<<endl;
        return;
    }
    for(int i = 1 ; i < k ; i++){
        ans1 = ans1 + '1';
    }
    ans1 = ans1 + value ;
    cout<<"sss : "<<ans1<<endl;
    ans.insert( { ans1 , sl++} );
}
void in1(string u){
    cout<<u[0];
    for(int i = 1 ; i < u.size(); i++){
        cout<<'.'<<u[i];
    }
    cout<<endl;
}

void solve(){
    int n ;
    cin>>n;
    ans.clear();
    for(int i = 0 ,x  ; i < n ; i++){
        debug(i);
        cin>>x ;
        ans1 = "";
        a[x]++;
        in(   a[x] , to_string(x) );
        for(auto o : ans){
            //in1( o.fi );
        }
    }
    for(int i = 0 ; i <= n ; i++){
        a[i] = 0 ;
    }
    //ans.sort( ans.begin() , ans.end() , cmp );
    for(auto x : ans){
        in1( x.fi );
    }
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
