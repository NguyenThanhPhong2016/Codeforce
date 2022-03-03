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
signed main(){
    int p ;
    int n , k ; cin>>n>>k ;
    int h = n / k ;
    int ans = 0 ;
    if( k== 2 ){
        if( n%2 == 1 ){
            cout<<"-1"<<endl;
            return 0 ;
        }
        else{
            for(int i = 1 ; i <= n ; i= i + 2){
                cout<<"? "<<i<<" "<<i+1<<endl;
                fflush(stdout);
                cin>>p ;
                ans^= p ;
            }
            cout<<"! "<<ans<<endl;
        }
        return 0 ;
    }
    if( k ==1){
        for(int i = 1 ; i <= n ; i= i + 1){
            cout<<"? "<<i<<endl;
            fflush(stdout);
            cin>>p ;
            ans^= p ;
        }
        cout<<"! "<<ans<<endl;
        return 0;
    }
    for(int i = 0 ; i < h ; i++){
        cout<<"? ";
        for(int j = i* k + 1  ; j <= (i+1)*k ; j++ ){
            cout<<j<<" ";
        }
        fflush(stdout);
        cin>>p ;
        ans^= p ;
    }
    int mod = n%k ;
    if( mod == 0 ){
        cout<<"! "<<ans<<endl;
        return 0;
    }
    else if( mod %2 ==0 ){
        int sl = mod>>1 ;
        cout<<"? ";
        for(int i = h*k + 1 ; i <= h*k + sl ; i++){
            cout<<i<<" ";
        }
        for(int i = 1 ; i <= k - sl ; i++){
            cout<<i<<" ";
        }
        fflush(stdout);
        cin>>p;ans^= p;
        cout<<"? ";
        for(int i = h*k + sl + 1 ; i <= h*k + mod ; i++){
            cout<<i<<" ";
        }
        for(int i = 1 ; i <= k - sl ; i++){
            cout<<i<<" ";
        }
        fflush(stdout);
        cin>>p;ans^= p;
        cout<<"! "<<ans<<endl;
    }
    else{
        if( k%2 == 0 ){
            cout<<-1<<endl;return 0;
        }
        int sl = ( k - mod  )>>1 ;
        if( sl * 3 <= n - mod ){
            int dem = 3 ;
            while(dem >= 1 ){
                cout<<"? ";
                for(int i = h * k + 1 ; i <= n ; i++ ){
                    cout<<i<<" ";
                }
                for(int j = 0 ; j<=2 ; j++){
                    if( j + 1== dem ) continue;
                    for(int i = sl * j + 1 ; i <= (j+1)*sl ; i++){
                        cout<<i<<" ";
                    }
                }
                dem--;
                fflush(stdout);
                cin>>p;ans^= p;
            }
            cout<<"! "<<ans<<endl;
            return 0;
        }
        int l = mod , r = mod ;
        int dem = 0;
        while( !(l % 2 == 0 && 0ll >= l ) ){
            dem++;
            l = k - r ;
            r = k - l + 2 * mod ;
        }
        debug(dem);
        l = gcd( n - mod , k - mod );
        l = k / l ;
        int q = l * ( k - mod );
        int bg = 1  ;
        int n1 = n - mod ;
        while( bg <= q ){
            cout<<"? ";
            for( int i = h*k+1 ; i <= n ; i++ ){
                cout<<i<<" ";
            }
            for( int i = 0 ; i < k - mod ; i++ ){
                cout<< ( bg+i +n1 - 1 )%n1 + 1 <<" ";
            }
            bg = bg + k - mod ;
            fflush(stdout);
            cin>>p;ans^= p;
        }
        cout<<"! "<<ans<<endl;
    }
}
