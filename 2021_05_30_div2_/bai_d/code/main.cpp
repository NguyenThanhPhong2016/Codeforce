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

mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 5e5 + 10 ;
const int x15 = 32768*2 ;
int dp[x15];
int s1[20];
void solve(){
    int n , m , p;cin>>n>>m>>p;
    string a[n];
    int n2 = n/2 ;
    if( n%2 == 1 ) n2++;
    for(int i = 0 ; i< n ; i++){
        cin>>a[i];
    }
    string now(m ,  '0');
    string ans(m ,  '0') ;
    //debug(ans);
    int l = 0 ;
    for(int o = 0 ; o < 50 ; o++){
        int x = rng() % n ;
        int dem = -1 ;
        for(int i = 0 ; i < m ; i++){
            if( a[x][i] =='1' ){
                dem++;
                s1[dem] = i ;
            }
        }
        int maxbt = 1<<(dem+1);
        for(int i = 0 ; i < n ; i++){
            int ans1 = 0 ;
            for(int j = 0 ; j <= dem ; j++){
                if( a[i][ s1[j] ] == '1' ){
                    ans1 += 1<<j;
                }
            }
            dp[ans1]++;
        }
        for(int j = 0 ; j <= dem ; j++ ){
            for(int i = 0 ; i < maxbt ; i++ ){
                if(  ( i >> j ) & 1 == 1  ){
                    dp[ i ^ ( 1 << j ) ] += dp[i];
                }
            }
        }
        for( int i = 0;  i < maxbt ; i++ ){
            if( dp[i] >= n2 ){
                if( __builtin_popcountl( i ) > l ){
                    l = __builtin_popcountl(i);
                    ans = now ;
                    for(int j = 0 ; j <= dem ; j++){
                        if( ( i>>j )&1 == 1 ){
                            ans[ s1[ j ] ] = '1';
                        }
                    }
                }
            }
        }
        for(int i = 0 ; i < maxbt ; i++){
            //cout<<i<<" "<<dp[i]<<endl;
            dp[i] = 0 ;
        }
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
