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

/*
const int mod = 1e9 + 7 ;
const int N = 1e5 + 10  ;
int fac[N];
int inv[N];
int power( int a , int  b){
    if( b == 0  ) return 1 ;
    int c=  b /2 ;
    c = power( a , c ) % mod ;
    c = ( c * c ) % mod   ;
    if( b % 2 == 1 ) c = (  c  * a )%mod;
    return c ;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=pow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
} */
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
const int N = 1e6 + 10 ;
int s[N] ;
int a1[N] ;
queue<int> ds ;
queue<int> ds1 ;
set<int> kt ;
int kt1[N] ;
int ktam[N] ;
int ktd[N] ;
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , q , id , d ;cin>>n>>q>>id>>d ;
    int a[n];
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i] ;
        a1[ a[i] ]++ ;
    }
    for(int i = 1 ; i< N ; i++){
        kt.insert( i );
        s[i] = -1 ;
    }
    ds.push(  a[id]  + d  );
    ds.push( a[id]  - d ) ;
    int dem =-1 ;
    int minb = d ;
    int maxb = d ;
    int sl = 0 ;
    while( ds.size() != 0 ){
        dem++; // debug(dem);
        while( ds.size() !=0  ){
            int x = ds.front();
            //debug(x);
            ds.pop() ;
            if( x < 0 ){
                if( ktam[N-1] == 0 && ktam[x + N ] == 0 ){
                    ds1.push( x + 1 );
                    ktam[x+N] = 1;
                }
                continue;
            }
            if( x >= N ){
                if( ktd[0] == 0 && ktd[x - N] == 0 ){
                    ds1.push( x - 1 );
                    ktd[x-N] = 1;
                }
                continue;
            }
            kt1[x] = -1 ;
            kt.erase( x ) ;
            //debug(x);
            if( x -1 >=1 && kt1[x-1] == 0 ){
                ds1.push( x-1 );
            }
            if( x + 1 < N  && kt1[x+1] == 0 ){
                ds1.push( x + 1 );
            }
            if(  a1[x] == 1 && s[x] == -1 ){
                s[x] = dem ;

                int minbt = x + minb ;
                int maxbt = x + maxb ;
                while( true ){
                    auto id1 = lower_bound( kt.begin() , kt.end() , minbt );
                    if( id1 == kt.end() || *id1 > maxbt  ) break;
                    while( id1 != kt.end() &&  *id1 <= maxbt   ){
                        ds.push( *id1 );
                        id1++;
                    }
                    break;
                }

                minbt = x - maxb ;
                maxbt = x - minb ;
                while( true ){
                    auto id1 = lower_bound( kt.begin() , kt.end() , minbt );
                    if( id1 == kt.end() || *id1 > maxbt  ) break;
                    while( id1 != kt.end() && *id1 <= maxbt  ){
                        ds.push( *id1 );
                        id1++;
                    }
                    break;
                }

            }
        }
        while( ds1.size() !=0 ){
            ds.push( ds1.front() );
            ds1.pop();
        }
        minb = max( 1ll , minb - 1 ) ;
        maxb = min( N -1 , maxb + 1 ) ;
    }
    s[ a[id] ] = 0 ;
    while( q-- ){
        int id1 , value ; cin>>id1>>value ;
        if( s[ a[id1] ] <= value ){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
