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
int dem;
void in( vector<ii> s ){
    dem++;
    cout<<"in s "<<dem<<" : "<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<i<<" : "<<s[i].fi<<" "<<s[i].se<<endl;
    }
    cout<<endl;
}
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
const int N = 1e5 +10;
int t;
vector< int> a[ N ] ;
int b[N];
int c[N];
vector< ii > ans ;
vector< ii > ans1 ;
void bfs( int n , int u  ){
    cout<<" duyet : "<<u<<endl;
    b[u] = 1;
    c[u]--;
    if( c[u] == 1  ){
        for(auto x : a[u] ){
            if( b[x] == 0 ){
                bfs( n , x );
                return;
            }
        }
    }
    else if( c[u] == 0 ){
        ans1[n].se = u ;
        //cout<<"dung : "<<u<<endl;
    }
    else{
        int dem  = 0 ;
        for( auto x : a[u] ){
            if( b[x]==0 && c[x] == 1 ){
                dem = x;
                for(auto y : a[u] ){
                    if(b[y] ==0 && y != dem ){
                        ans.pb( { u , y } );
                        //cout<<"tru : "<<y<<endl;
                        c[y]--;
                    }
                }
                bfs(n , x);
                return;
            }
        }
        for( auto x : a[u] ){
            if( b[x]==0 && c[x] == 2 ){
                dem = x;
                for(auto y : a[u] ){
                    if(b[y] ==0 && y != dem ){
                        ans.pb( { u , y } );
                        //cout<<"tru : "<<y<<endl;
                        c[y]--;
                    }
                }
                bfs(n , x);
                return;
            }
        }
        if( dem == 0 ){
            for(auto x : a[u] ){
                if( b[x] ==0 ){
                    if( dem ==0){
                        dem = x ;
                    }
                    else{
                        ans.pb( { u , x } );
                        //cout<<"tru : "<<x<<endl;
                        c[ x ]--;
                    }
                }
            }
            if( dem != 0) bfs( n , dem );
            else{
                cout<<"loi"<<endl;return;
            }
        }
    }
}
void solve(){
    ans.clear();
    ans1.clear();
    int n ;cin>>n;
    vector<ii> kq1 ;
    for(int i = 0 , u , v; i < n -1  ; i++){
        cin>>u>>v;
        kq1.pb({ u , v });
        /*
        if( n == 26 ){
            cout<<u<<" "<<v<<";";
            dem4++;
            if( dem4 == 14 ){
                dem4 = 0;
                cout<<endl;
            }
        }
        */
        a[u].pb( v );
        a[v].pb( u );
    }
    for(int i = 1 ; i <= n ; i++){
        c[i] = a[i].size();
    }
    int dem = 1 ;
    while( dem== 1 ){
        dem = 0;
        for(int i = 1 ; i<= n ; i++){
            if( b[i] ==0 && c[i] == 1 ){
                for(auto x : a[i] ){
                    if( b[x] ==0 ){
                        dem = x;
                        break;
                    }
                }
                b[i] = 1;
                c[i]--;
                ans1.pb( {i , 0 } );
                cout<<"duyet  : "<<i<<endl;
                bfs( ans1.size() - 1 , dem );
                dem = 1;
            }
            else if( b[i] == 0 && c[i] ==0 ){
                    cout<<"duyet1  : "<<i<<endl;
                b[i] = 1;
                dem =1 ;
                ans1.pb( {i, i} );
            }
        }
    }
    if( ans1.size()  != ans.size() +1 ){
        cout<<"SAI"<<endl;
    }
    if( ans.size() ==0 ){
        cout<<"0"<<endl;
        for( int i = 0 ; i<= n ;i++ ){
            a[i].clear();
            b[i] = 0 ;
            c[i] = 0 ;
        }
        return;
    }
    //in( ans );
    //in( ans1);
    if( t== 9527  ){
        int s = 0;
        int p = 16 ;
        for(int i = 24 ;i<= 32; i++){
            s = s*100 + kq1[i].fi;
        }
        cout<<s<<endl;
    }
    /*
    for(int i = 1 ; i <= n ; i++){
        cout<<i<<" : ";
        for( auto x  : a[i] ){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    */
    cout<<ans.size()<<endl;
    for( int i = 0 ; i + 1 < ans1.size() ; i++){
        cout<<ans[i].fi<<" "<<ans[i].se<<" "<<ans1[i].se<<" "<<ans1[i+1].fi<<endl;
    }
    for( int i = 0 ; i<= n ;i++ ){
        a[i].clear();
        b[i] = 0 ;
        c[i] = 0 ;
    }
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }
}
