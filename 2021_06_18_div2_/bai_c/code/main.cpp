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
    int x , y , bg;
    for(int i = 0 ; i< n ; i++){
        cin>>a[i];
    }
    sort( a, a + n  );
    int minbt = 1e9 + 10  ;
    for(int i = 0 ; i + 1 < n ; i++){
        minbt = min(minbt , a[i+1] - a[i] );
    }
    for(int i = 0 ; i + 1 < n ; i++){
        if( a[i+1] - a[i] ==  minbt  ){
            x = a[i];
            y = a[i+1];
            bg = i;
            break;
        }
    }
    cout<<a[bg]<<" ";
    for(int i = bg + 2 ; i < n ; i++){
        cout<<a[i]<<" ";
    }
    for(int i = 0 ; i < bg ; i++){
        cout<<a[i]<<" ";
    }
    cout<<a[bg+1]<<endl;

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
