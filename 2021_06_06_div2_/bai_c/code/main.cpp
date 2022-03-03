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
const int maxbt = 1e9 ;
void solve(){
    int n ;cin>>n;
    string a ;cin>>a;
    a= " "+a;
    n = a.size()  -1;
    int d[n+1] ;
    int k[n+1] ;
    d[0] = 0 ;
    k[0] = 0 ;
    for(int i = 1 ; i <= n ; i++ ){
        if( a[i] == 'D' ){
            d[i] = d[i-1] + 1 ;
            k[i] = k[i-1] ;
        }
        else{
            d[i] = d[i-1] ;
            k[i] = k[i-1] +1 ;
        }
    }
    int ans[n+1];
    for(int i = 1 ; i <= n ; i++){
        ans[i] = 1;
    }
    for(int i = 1 ;  i <= n ; i++){
        if( a[i] == 'D' ){
            ans[i] = i ;
        }
        else{
            break;
        }
    }
    for(int i = 1 ;  i <= n ; i++){
        if( a[i] == 'K' ){
            ans[i] = i ;
        }
        else{
            break;
        }
    }
    map< ii , int > sss;
    for(int i = 1 ; i <=  n ; i++ ){
        if( ans[i] == i ) continue;
        int dem = 1 ;
        int x = d[ i ] ;
        int y = k[ i ] ;
        int z = gcd( d[i] , k[i] );
        int t = i / z ;
        x = x / z ;
        y = y/z ;
        if( sss.find( { x , y }   )== sss.end() ){
            sss[ {x , y} ]++;
        }
        else{
            continue;
        }
        int l = t ;
        for(int j =  i + t ; j <= n ; j = j + t ){
            if( false ){
                debug( i );
                debug( j );
                debug(dem);
            }
            int u = d[ j ] - d[j - l] ;
            int v = k[ j ] - k[j - l] ;
            if(  x*v == u  * y  ){
                if( false ){
                    cout<<"dem : "<<dem<<endl;
                    debug( x );
                    debug( y );
                    debug( u );
                    debug( v );
                    debug( i );
                    debug(j);
                }
                dem++;
                ans[j] = max( ans[j] ,  dem   );
                l = t ;
            }
            else{
                l = l + t;
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if( ans[i] == -1 ){
            //while(true);
        }
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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
