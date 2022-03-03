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
struct point{
    int in ;
    int ax ;
    int sl ;
};
vector< point > ss ;
void solve(){
    int n , k ;cin>>n>>k;
    int a[n];
    for(int i = 0 ;i < n ; i++){
        cin>>a[i];
        a[i] -= k ;
    }
    int bg = 0 ;
    int ans = 1 ;
    int z = k + k ;
    ss.pb( {a[0] , a[0] + z ,  1 } );
    for( int i = 1 ; i < n ; i++ ){
        //debug(i);
        if( a[i] <= a[i-1] + z && a[i] >= a[i-1]   ){
            for(int j  = ss.size() -1  ; j >= bg ; j--){
                if(  ss[j].ax >= a[i]  ){
                    ss[j].in = max( a[i] , ss[j].in );
                }
                else{
                    bg = j + 1 ;
                    break;
                }
            }
        }
        else if( a[i] < a[i-1] ){
            if( a[i] + z >= a[i-1] ){
                for(int j  = ss.size() -1  ;j >= bg ; j--){
                    if(  ss[j].in  <= a[i] + z  ){
                        ss[j].ax = min( a[i] + z  , ss[j].ax );
                    }
                    else{
                        bg = j + 1 ;
                        break;
                    }
                }
            }
            else{
                bg = ss.size()  ;
            }
        }
        else{
            bg = ss.size();
        }
        //debug(bg);
        ss.pb( { a[i] , a[i] + z  , 1 } );
        for(int j = bg ; j + 1 < ss.size() ; j++ ){
            ss[j].sl++;
        }
        bg = 0 ;
        //for(int j = 0 ; j < ss.size() ; j++ ){
        //    cout<<" so j : "<<ss[j].in<<" "<<ss[j].ax<<" "<<ss[j].sl<<endl;
        //}
    }
    for(auto x : ss){
        ans = max( ans , x.sl );
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t=1;
    while(t--){
        solve();
    }
}
