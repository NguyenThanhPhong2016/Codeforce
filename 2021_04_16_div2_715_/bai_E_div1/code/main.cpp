#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
const int N = 3e5 + 2 ;
int n;
vector<int> b[N+1];
int value[N+1];
int value1[N+1];
int c[N+1];
int d[N+1];
int e[N+1];
int f[N+1];
int ans[N+1];
int bacdinh[N+1];
int kqbt ;
int kiemtra1[N][3];
int kiemtra[N+1];
void dfs( int x , int bac ){
    for(auto m : b[x] ){
        bacdinh[m] = bac ;
        if( b[m].size() !=0 ){
            dfs( m ,bac + 1 );
        }
        else{
            d[m] = 1 ;
        }
    }
}
void dfs2(int x){
    for(int i = 0 ; i < b[x].size();i++){
        dfs2( b[x][i] );
        kiemtra1[x][2] += kiemtra1[ b[x][i] ][2] ;
        kiemtra1[x][0] = min( kiemtra1[x][0] , kiemtra1[ b[x][i] ][  0  ] );
        kiemtra1[x][1] = max( kiemtra1[x][1] , kiemtra1[ b[x][i] ][  1  ] );
    }
    kiemtra1[x][2] += 1 ;
    if( kiemtra1[x][0] <= ans[x]){
        cout<<"NO"<<endl;
        exit(0);
    }
    kiemtra1[x][0] = min( kiemtra1[x][0] , ans[x] );
    kiemtra1[x][1] = max( kiemtra1[x][1] , ans[x] );
    if( kiemtra1[x][1] - kiemtra1[x][0] +1 != kiemtra1[x][2]  ){
        cout<<"NO"<<endl;
        exit(0);
    }
}
void dfs3(int x){
    for(int i = 0 ; i < b[x].size();i++){
        if( f[ b[x][i] ] == 1 ) continue;
        dfs3( b[x][i] );
        kiemtra1[x][2] += kiemtra1[ b[x][i] ][2] ;
        kiemtra1[x][0] = min( kiemtra1[x][0] , kiemtra1[ b[x][i] ][  0  ] );
        kiemtra1[x][1] = max( kiemtra1[x][1] , kiemtra1[ b[x][i] ][  1  ] );
    }
    kiemtra1[x][2] += 1 ;
    if( kiemtra1[x][0] <= value[x] ){
        cout<<"NO"<<endl;
        exit(0);
    }
    kiemtra1[x][0] = min( kiemtra1[x][0] , value[x] );
    kiemtra1[x][1] = max( kiemtra1[x][1] , value[x] );
    if( kiemtra1[x][1] - kiemtra1[x][0] +1 != kiemtra1[x][2]  ){
        cout<<"NO"<<endl;
        exit(0);
    }
}
void in(){
    for(int i = 1 ;  i<= n;i++){
        if( ans[i] == 0 ) ans[i] = value[i];
    }
    for(int i =1 ; i <= n; i++){
        kiemtra[ ans[i] ]++;
    }
    for(int i = 1 ; i <=n ; i++){
        if( kiemtra[i]!=1 ){
            cout<<"NO"<<endl;
            exit(0);
        }
    }
    for(int i = 1; i<= n ; i++){
        kiemtra1[i][0] =  N ;
        kiemtra1[i][1] =  0 ;
        kiemtra1[i][2] = 0;
    }
    dfs2( 1 );
    cout<<"YES"<<endl;
    cout<<kqbt<<endl;
    for(int i = 1 ;i <= n; i++){
        cout<<ans[i]<<" ";
    }
}
void solve(){
    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        cin>>value[i];
        value1[ value[i] ] = i ;
    }
    for(int i = 1 ,x,y ; i <= n -1 ; i++){
        cin>>x>>y;
        b[x].push_back( y ) ;
        c[y] = x ;
    }
    for(int i = 1; i<= n ;i++ ){
        e[i] = b[i].size();
    }
    dfs( 1 , 1 );
    ans[1] = 1 ;
    int sotruoc = 1;
    int xacdinh = 1;
    for(int i = 1 ; i <= n ; i++){
        if( d[ value1[i] ] == 1  ){
            int j = value1[i] ;
            f[j] = 1;
            kqbt += bacdinh[j];
            vector<int> s ;
            while( ans[j] == 0 ){
                //cout<<"j: "<<j<<" : "<<ans[j]<<endl;
                s.push_back( j );
                j = c[j];
            }
            s.push_back( j );
            int check = 0 ;
            for(int k = s.size() - 1 ; k>=0 ;k--){
                if( s[k] == sotruoc ){
                    check =1;
                    break;
                }
            }
            if( check == 0 ){
                cout<<"NO"<<endl;
                return;
            }
            //h = xacdinh +1;
            for(int k =( (int) s.size() ) -2; k>=0 ;k--){
                ans[ s[k] ] = xacdinh + 1 ;
                xacdinh++;
            }
            int l =  c[ value1[i] ] ;
            sotruoc = l ;
            if( e[l] == 1 ){
                d[l] =1;
            }
            else{
                e[l]--;
            }
        }
        else{
            int j = value1[i] ;
            f[j] = 1;
            kqbt+= bacdinh[j];
            vector<int> s ;
            while( ans[j] == 0 ){
                s.push_back( j );
                j = c[j];
            }
            s.push_back( j ) ;
            //h = xacdinh +1;
            for(int k =( (int) s.size() ) -2 ; k>=0 ;k--){
                ans[  s[k] ] = xacdinh + 1 ;
                xacdinh++;
            }
            vector<int> duyet ;
            int u = c[j];
            while( u !=0 ){
                duyet.push_back( u );
                u = c[u];
            }
            int ikt = i ;
            for(int v =( (int) duyet.size() ) -1 ; v >=0 ; v-- ){
                ikt++;
                if( value[ duyet[v] ] != ikt ){
                    cout<<"NO"<<endl;
                    return;
                }
            }
            for(int i = 1; i<= n ; i++){
                kiemtra1[i][0] =  N ;
                kiemtra1[i][1] =  0 ;
                kiemtra1[i][2] = 0;
            }
            for(int o = 0 ;o < b[value1[i] ].size() ; o++){
                dfs3( b[value1[i]][o] );
            }
            in();
            return;
        }
    }
    in();
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}
