#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
const int N = 1001;
map< ii , int > aaa;
void in( int x , int y ){
    cout<<x<<" "<<y<<endl;
}
void xuli( pair<ii,int> sss , int value  ){
    int x = sss.fi.fi;
    int y = sss.fi.se;
    int z = sss.se ;
    if( aaa.find( {x -1 ,y} ) != aaa.end() ){
        if( aaa.find( {x -1  ,y +1} ) != aaa.end() ){
            if( aaa.find( {x - 2 ,y +1 } ) != aaa.end() ){
                in( x ,y );
            }
            if( aaa.find( {x  ,y +1 } ) != aaa.end() ){
                in( x ,y );
            }
        }
        if( aaa.find( {x -1  , y -1 } ) != aaa.end() ){
            if( aaa.find( {x - 2 ,y - 1 } ) != aaa.end() ){
                in( x ,y );
            }
            if( aaa.find( {x  ,y - 1 } ) != aaa.end() ){
                in( x ,y );
            }
        }
        if( aaa.find( {x + 1  ,y + 1} ) != aaa.end() ){
            if( aaa.find( {x  ,y +1 } ) != aaa.end() ){
                in( x ,y );
            }
        }
        if( aaa.find( {x + 1  ,y - 1} ) != aaa.end() ){
            if( aaa.find( {x  ,y -1 } ) != aaa.end() ){
                in( x ,y );
            }
        }
    }
    if( aaa.find( {x + 1 , y} ) != aaa.end() ){
        if( aaa.find( {x +1  ,y +1} ) != aaa.end() ){
            if( aaa.find( {x  ,y +1 } ) != aaa.end() ){
                in( x ,y );
            }
            if( aaa.find( {x + 2 ,y +1 } ) != aaa.end() ){
                in( x ,y );
            }
        }
        if( aaa.find( {x +1 ,y -1 } ) != aaa.end() ){
            if( aaa.find( {x +2 ,y - 1 } ) != aaa.end() ){
                in( x ,y );
            }
            if( aaa.find( {x ,y - 1 } ) != aaa.end() ){
                in( x ,y );
            }
        }
        if( aaa.find( {x - 1  ,y + 1} ) != aaa.end() ){
            if( aaa.find( {x  ,y +1 } ) != aaa.end() ){
                in( x ,y );
            }
        }
        if( aaa.find( {x - 1  ,y - 1} ) != aaa.end() ){
            if( aaa.find( {x  ,y - 1 } ) != aaa.end() ){
                in( x ,y );
            }
        }
    }
}
void solve(){
    int n ;cin>>n;
    for(int i  =0 , a , b ,c ; i< n ; i++){
        cin>>a>>b>>c;
        aaa.insert(pair<ii,int>( {a,b} , c ) );
    }
    for(auto x : aaa){
        xuli( x ,0ll  );
    }

}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t = 1 ;
    while(t--){
        solve();
    }
}
