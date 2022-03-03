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
struct node{
    int in , ax , cnt ;
};
vector<node>  s  ;
void solve(){
    int n , k ;
    cin>>n>>k;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
        a[i] -= k;
    }
    int z = k  +  k ;
    for(int i = 0 ;i < n ; i++){
        //s.pb( { a[i] , a[ i] + z , 0 }  );
        int p = s.size() ;
        for( int i = 0 ; i < p ; i++ ){
            auto x = s[i];
            if( a[i] <= x.ax && a[i] >= x.in   ){
                s.pb( { a[i] , x.ax , x.cnt+1  } );
            }
            else if( a[i] < x.in ){
                if( a[i] + z  >= x.in ){
                    s.pb( { x.in , a[i] + z , x.cnt+1  } );
                }
            }
        }
        s.pb( { a[i] , a[ i] + z , 1 }  );
    }
    int ans = 1 ;
    /*
    for(auto x : s){
        cout<<x.in<<" "<<x.ax<<" "<<x.cnt<<endl;
    }
    */
    for(auto x : s){
        ans = max( ans, x.cnt );
    }
    cout<<ans<<endl;
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
