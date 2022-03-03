#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
const int N = 2e5 + 4 ;
int a[N];
int min0[N];
int minn[N];
vector<int> v[N];
int colorbt ;
int b[N] ;
void dfs( int u , int dem , int color ){
    //cout<<u<<" : "<<dem<<endl;
    dem++;
    for( auto x :  v[u] ){
        if( b[x] ==0 ){
            b[x] = 1;
            min0[ x ] = min( min0[x] , dem );
            if( a[x] == 1 ){
                if( color == 1  ){
                    //cout<<u<<" : "<<x<<endl;
                    colorbt  =1 ;
                }
                dfs( x , dem , 1 ) ;
            }
            else dfs( x , dem , 0 ) ;
            b[x] = 0;
        }
    }
}
void dfs1( int u , int dem ){
    dem++;
    for( auto x :  v[u] ){
        if( b[x] == 0  ){
            b[x] =1;
            minn[ x ] = min( minn[x] , dem );
            dfs1( x , dem ) ;
            b[x] = 0;
        }
    }
}
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    colorbt  = 0 ;
    int n , m , k ;cin>>n>>m>>k;
    for(int i = 0 ,x  ;i < k ; i++){
        cin>>x;x--;
        a[x] = 1;
    }
    for(int i = 0,x,y ; i < m ; i++){
        cin>>x>>y;
        x--;y--;
        v[x].pb( y ) ;
        v[y].pb( x ) ;
    }
    for(int i = 0 ;i < N ;i++){
        min0[i] = N ;
        minn[i] = N ;
    }
    b[0] = 1;
    if( a[0] ==1 ) dfs( 0 , 0 , 1 );
    else dfs( 0 , 0 , 0 ) ;
    b[0] = 0;
    b[n-1] = 1;
    dfs1( n-1 , 0 ) ;
    b[n-1] = 0;
    if( colorbt ==1  ){
        cout<<"mintb"<<min0[n-1]<<endl;
        return;
    }
    /*
    ii maxbt0[2] ;
    ii maxbtn[2] ;
    maxbt0[0].fi = -1;
    maxbt0[1].fi = -1;
    maxbtn[0].fi = -1;
    maxbtn[1].fi = -1;
    int minbt = min0[n-1] ;
    for(int i = 0 ;i < n ; i++){
        if( a[i] ==1 ){
            if( min0[i] >= maxbt0[1].fi ){
                maxbt0[0] = maxbt0[1];
                maxbt0[1].fi = min0[i];
                maxbt0[1].se = i;
            }
            else if( min0[i] >= maxbt0[0].fi ){
                maxbt0[0].fi = min0[i];
                maxbt0[0].se = i ;
            }
            if( minn[i] >= maxbtn[1].fi ){
                maxbtn[0] = maxbtn[1];
                maxbtn[1].fi = minn[i];
                maxbtn[1].se = i;
            }
            else if( min0[i] >= maxbt0[0].fi ){
                maxbtn[0].fi = minn[i];
                maxbtn[0].se = i ;
            }
        }
    }
    cout<<"max0"<<endl;
    for(int i =0 ; i <= 1 ;i++){
        cout<<i<<" "<<maxbt0[i].fi<<" "<<maxbt0[i].se<<endl;
    }
    cout<<"maxn"<<endl;
    for(int i =0 ; i <= 1 ;i++){
        cout<<i<<" "<<maxbtn[i].fi<<" "<<maxbtn[i].se<<endl;
    }
    if( maxbt0[1].se != maxbtn[1].se ){
        if( minbt >  maxbt0[1].fi + maxbtn[1].fi + 1  ){
            minbt =  maxbt0[1].fi + maxbtn[1].fi + 1  ;
        }
    }
    else{
        if( minbt >  maxbt0[0].fi + maxbtn[1].fi + 1  ){
            minbt =  maxbt0[0].fi + maxbtn[1].fi + 1  ;
        }
        if( minbt >  maxbt0[1].fi + maxbtn[0].fi + 1  ){
            minbt =  maxbt0[1].fi + maxbtn[0].fi + 1  ;
        }
    }
    cout<<minbt<<endl;
    */

    ii
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; t =1 ;
    while(t--){
        solve();
    }
}
