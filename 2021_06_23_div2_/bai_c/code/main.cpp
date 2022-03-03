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
int xuli(int value ,  int x ){
    if( value % x ==0 ) return value/x -1 ;
    else return value/x ;
}
void solve(){
    int n , k , x ;
    cin>>n>>k>>x;
    int a[n];
    for(int i = 0; i< n ;i++){
        cin>>a[i];
    }
    sort( a , a + n  );
    vector<int> s ;
    int ans = n ;
    for(int i = 1 ; i < n ; i++){
        if( a[i] - a[ i-1 ] > x ){
            s.pb( xuli( a[i] - a[i-1] , x  ) );
        }
        else{
            ans--;
        }
    }
    //debug(ans);
    if( s.size() ==0 ){
        cout<<1<<endl;return;
    }
    sort( s.begin(),s.end() );
    for(int i = 0 ; i < n ; i++){
        //debug(s[i]);
        if( k >= s[i] ){
            k-= s[i];
            ans--;
        }
        else break;
    }
    cout<<max(ans,1ll)<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
