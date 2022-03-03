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
    int n , q ; cin>>n>>q;
    string s ;cin>>s;
    int a[n];
    a[0] = s[0] - 'a' + 1  ;
    for(int i = 1 ; i < n ; i++){
        a[i] = a[i-1] + s[i] - 'a'+1;
        //debug(a[i]);
    }
    while(q--){
        int l , r ; cin>>l>>r;l--;r--;
        if( l==0 ){
            cout<<a[r]<<endl;continue;
        }
        cout<<a[r] - a[l-1]<<endl;
    }
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
