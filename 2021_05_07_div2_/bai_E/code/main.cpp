#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define endl "\n"
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
int tinh( int n ){
    int c = n/2;
    return n*n - c*c ;
}
bool tinh1( int n , int value  ){
    if( n%2 ==1 ){
       int h = ( n+1 )/2;
       int h1 = n*h ;
       if( h1 >= value ) return false;
       else{
            return true;
       }
    }
    else{
        int h = n /2 ;
        int h1 = n*h ;
        if( h1 >= value ) return false;
        else{
            return true;
        }
    }
}
int tinh2( int n  , int value  ){
    if( n%2 ==1 ){
       int h = ( n+1 )/2;
       int h1 = n*h ;
       if( h1 >= value ) return 0;
       else{
            return value - h1;
       }
    }
    else{
        int h = n /2 ;
        int h1 = n*h ;
        if( h1 >= value ) return 0;
        else{
            return value - h1;
        }
    }
}
const int N = 1e3 + 10 ;
int kq[N][N];
void in(int maxbt){
    cout<<maxbt<<endl;
    for(int i = 1 ; i <= maxbt ; i++ ){
        for(int j = 1 ; j <= maxbt ; j++){
            cout<<kq[i][j]<<" ";
            kq[i][j] = 0;
        }
        cout<<endl;
    }
}
void solve(){
    int m , k ;cin>>m>>k;
    //cout<<m<<" "<<k<<endl;
    int a[k+1];
    int maxbt1 = 0;
    vector<int> v;
    set< ii > ss;
    for( int i = 1 ; i <= k ; i++ ){
        cin>>a[i];
        maxbt1 = max( maxbt1 , a[i] ) ;
        ss.insert( {a[i] , i} );
    }
    for( auto x : ss ){
        for(int i = 0 ; i < x.fi ; i++){
            v.pb( x.se );
        }
    }
    if( m <=3 ){
        if( m== 1 ){
            cout<<"1"<<endl;
            cout<<v[0]<<endl;
        }
        else{
            kq[1][1] = v[0];
            kq[1][2] = v[1];
            if( m == 3 ){
                if( v[0] == v[1] && v[1] == v[2] ){
                    kq[1][3] = v[2];
                    in( 3 );
                    return;
                }
                if( v[1] != v[2] ){
                    kq[2][1] = v[2];
                    in(2) ;
                }
                else{
                    kq[1][1] = v[2];
                    kq[2][1] = v[0];
                    in(2);
                }
                return;
            }
            in( 2 );
        }
        return;
    }
    int maxbt = 1 ;
    while( tinh(maxbt) < m ) maxbt++;
    while( tinh1( maxbt , maxbt1 ) ) maxbt++;
    //cout<<"maxbt : "<<endl;
    int dem =  m ;
    for(int i = 1 ; i <= maxbt ; i = i +2 ){
        for(int j = 1 ; j <= maxbt ; j++){
            if( i%2 == 0 && j %2 ==0 ){
                continue;
            }
            else{
                dem--;
                if( dem < 0 ) continue;
                kq[i][j] = v[dem];
            }
        }
    }
    if( dem < 0 ){
        in(maxbt);
        return;
    }
    int value = v[dem];
    int dem1 = 0;
    for(int i = dem ; i < m ;i++){
        if( v[i] == v[dem] ) dem1++;
    }
    //cout<<"dem1 : "<<dem1<<endl;
    if( v[dem] != v[m-1] ){
        if( maxbt % 2 == 1 ){
            int x = 1 , y = 1  , z = maxbt ,t = maxbt - 1 ;
            int dem2 = 2;
            while( dem2 <= dem1  ){
                dem2 = dem2 + 2;
                //cout<<x<<" "<<y<<" "<<z<<" "<<t<<endl;
                int l = kq[z][t];
                kq[ z ][t] = kq[ x ][y];
                kq[x][y] = l;
                y = y +2 ;
                if( y > maxbt ){
                    x = x + 2;
                    y = 1;
                }
                t = t - 2;
                if( t < 1 ){
                    z = z - 2 ;
                    t =  maxbt - 1;
                }
            }
        }
        else{
            int x = 1 , y = 1  , z = maxbt -1 ,t = maxbt ;
            int dem2 = 1;
            while( dem2 <= dem1  ){
                dem2 = dem2 + 2;
                //cout<<x<<" "<<y<<" "<<z<<" "<<t<<endl;
                int l = kq[z][t];
                kq[ z ][t] = kq[ x ][y];
                kq[x][y] = l;
                y = y +2 ;
                if( y > maxbt ){
                    x = x + 2;
                    y = 1;
                }
                t = t - 2;
                if( t < 1 ){
                    z = z - 2 ;
                    t =  maxbt;
                }
            }
        }
    }
    for(int i = 2 ; i <= maxbt ; i = i +2 ){
        for(int j = 1 ; j <= maxbt ; j++){
            if( i%2 == 0 && j %2 ==0 ){
                continue;
            }
            else{
                dem--;
                if( dem < 0 ) continue;
                //cout<<dem<<" : ???"<<v[dem]<<endl;
                kq[i][j] = v[dem];
            }
        }
    }
    in(maxbt);
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        //cout<<"T :"<<t+1<<endl;
        solve();
    }
}
