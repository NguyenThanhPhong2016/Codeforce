#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define endl "\n"
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
const int N = 2e5 + 10 ;
int b[N] ;
vector<int> a1[N];
int value ;
int sz ;
void duyet( int u , int dem   ){
    if( u == dem  ){
        value++ ;
        return;
    }
    for(auto x : a1[u]){
        if( b[x] == 0 ){
            duyet( x , dem );
            if( value != 0 ){
                value++;
                if( u < dem ){
                    sz += a1[x].size() ;
                }
                b[x] = 1;
                break;
            }
        }
    }
}
void solve(){
    value = 0 ;
    sz = 0;
    int n ; cin>>n;
    ii a[n];
    for(int i = 0 ; i < n -1  ; i++){
        cin>>a[i].fi>>a[i].se;
        a1[ a[i].fi ].pb( a[i].se );
        a1[ a[i].se ].pb( a[i].fi );
    }
    int ans[n+1];
    ans[0] = 0 ;
    for(int i = 0 ; i < a1[0].size() ;i++){
        int x =a1[ a1[0][i] ].size();
        if( x == 1 ) continue;
        cout<<"x : "<<x<<endl;
        ans[0] += x*(x-1)/2;
    }
    b[0] = 1 ;
    int dem = 0 ;
    int beginbt = 0 ;
    int endbt = 0;
    while( dem < n-1 ){
        dem++;
        if( b[dem] == 1 ){
            ans[dem] = 0 ;
            continue;
        }


    }
    for(int i = 0 ; i <= n + 1  ;i++){
        b[i] = 0;
        a1[i].clear();
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
