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
    int n ,m ;cin>>n>>m;
    if( m > n  ) m = n ;
    string s ;cin>>s;
    string a = s;
    for(int i = 0 ; i <  m ; i++){
        a = s;
        for(int j = 0 ; j < n ;j++){
            if( s[j] == '1' ){
                continue;
            }
            else{
                if( j == 0 ){
                    if( s[j+1] == '1' ) a[j] = '1';
                }
                else if( j ==n -1 ){
                    if( s[j-1] == '1' ) a[j] ='1';
                }
                else{
                    if( s[j-1] == '1' && s[j +1 ]== '0' ){
                        a[j] = '1';
                    }
                    else if( s[j-1 ] == '0' && s[j+1] == '1' ){
                        a[j] = '1';
                    }
                }
            }
        }
        s = a;
    }
    cout<<s<<endl;
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
