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
bool cmp( ii x , ii y ){
    return x.se < y.se ;
}
const int N = 1e5 + 10;
int s[N];

void solve(){
    int n ; cin>>n ;
    vector<ii> a;
    int sum  = 0;
    for(int i = 0;  i < n ; i++){
        int x , y ; cin>>x>>y ;
        sum+= x ;
        a.pb( { x , y  }  );
    }
    sort( a.begin() , a.end() , cmp );
    int ans = 0 ;
    int dem = 0 ;
    s[0] = a[0].fi;
    for(int i = 1 ; i < n ; i++){
        s[i] = s[i-1] + a[i].fi ;
    }
    for(int i = 0 ; i < n ; i++){
        s[i] = sum - s[i] ;
    }
    for(int i = 0 ;  i < n; i++){
        //debug(dem);debug(ans) ;
        if( dem >= a[i].se ){
            if( dem <= sum - a[i].fi ){
                dem += a[i].fi ;
                ans += a[i].fi ;
            }
            else{
                ans = ans + sum - dem ;
                break;
            }
            continue;
        }
        int h = a[i].se - dem ;
        if( h >= sum - dem ){
            ans += ( sum -dem  )*2  ;
            break;
        }
        dem += h ;
        ans += h*2 ;
        if( dem <= sum - a[i].fi ){
            dem += a[i].fi ;
            ans += a[i].fi ;
            //cout<<1<<" : ";debug(dem); debug(ans);
        }
        else{
            ans += ( sum - dem );
            //cout<<2<<" : ";debug(dem);debug(ans);
            break;
        }
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; t= 1 ;
    while(t--){
        solve();
    }
}
