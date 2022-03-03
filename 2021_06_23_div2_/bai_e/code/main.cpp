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
const int N = 1e5 + 10 ;
int ans[N];
void in(int n ){
    cout<<"YES"<<endl;
    for(int i = 0 ; i < n ; i++){
        cout<<ans[i]<<" ";
    }
}
struct node{
    int value ;
    int l0 , r0 ;
    int l1 , r1 ;
    int cnt  ;
    node( int a , int b , int c , int d , int e  ){
        value = a ;
        l0 = b ;
        r0 = c ;
        l1 = d ;
        r1 = e ;
    }
    void capnhat0( int l , int r ){
        l0 = max( l0 , l );
        r0 = min( r0 , r );
    }
    void capnhat1(int l , int r ){
        l1 = max( l1 , l );
        r1 = min( r1 , r );
    }
    void cnt_(  ){
        if( value >= l0 && value <= r0 ){
            if( value >= l1 && value <= r1  ){
                cnt = 2 ;
            }
            else{
                cnt = 0 ;
            }
        }
        else{
            if( value >= l1 && value <= r1  ){
                cnt = 1 ;
            }
            else{
                cnt = -1 ;
            }
        }
    }
};
vector< node > a ;
void No( int i ){
    /*
    cout<<"\n\n\n"<<endl;
    for(int j = 0 ; j < a.size() ; j++){
        i = j ;
        debug(i);
        debug( a[i].value  );
        debug( a[i].l0  )   ;
        debug( a[i].r0  )   ;
        debug( a[i].l1  )   ;
        debug( a[i].r1  )   ;
        debug( a[i].cnt  )   ;
    }
    */
    cout<<"NO"<<endl;return ;
}
void solve(){
    int p = 0 ;
    int n , m ; cin>>n>>m;
    for(int i = 0; i  < n ; i++){
        ans[i] = -1 ;
        int o , b , c , d , e;cin>>o>>b>>c>>d>>e;
        a.pb( { o , b , c , d , e } );
    }
    int dem = 0 ;
    int ed = n -1 ;
    for(int i  =  n -1 ; i >= 0 ; i--){
        a[i].cnt_();
        ///*
        debug(i);
        debug( a[i].value  );
        debug( a[i].l0  )   ;
        debug( a[i].r0  )   ;
        debug( a[i].l1  )   ;
        debug( a[i].r1  )   ;
        debug( a[i].cnt  )   ;
        //*/
        if( i==0 ){
            if( dem ==0  ){
                if( a[i].cnt == 2 ){
                    if( a[i].l0 <= 0 && a[i].r0 >=0 ){
                        ans[i] = 1 ;
                        in(n);
                        return ;
                    }
                    else{
                        if( a[i].l1 <= p && a[i].r1 >=p ){
                            ans[i] = 0;
                            in(n);
                            return ;
                        }
                        else{
                            No(i);
                            return;
                        }
                    }
                }
                else if( a[i].cnt == 0 ){
                    if( a[i].l1 <= p && a[i].r1 >=p ){
                        ans[i] = 0 ;
                        in(n) ;
                        return ;
                    }
                    else{
                        No(i);
                        return;
                    }
                }
                else if( a[i].cnt == 1  ){
                    if( a[i].l0 <= 0 && a[i].r0 >=0 ){
                        ans[i] = 1 ;
                        in(n);
                        return ;
                    }
                    else{
                        No(i);
                        return;
                    }
                }
                else{
                    No(i);
                    return;
                }
            }
            else{
                int x = a[i].value ;
                if( a[i].cnt == 1 ){
                    ans[i] = 1 ;
                    if( x >= a[i+1].l1 && x <= a[i+1].r1  ){
                        a[i+1] = 0 ;
                    }else{
                        a[i+1] = 1 ;
                        a[i].capnhat0( a[i+1].l0 , a[i+1].r0 );
                    }
                    if( a[i].l0 <= 0 && a[i].r0 >= 0 ){
                        in(n);
                        return ;
                    }
                    else{
                        No(i);
                        return;
                    }
                }
                else if( a[i].cnt == 0 ){
                    ans[i] = 0 ;
                    if( x >= a[i+1].l0 && x <= a[i+1].r0  ){
                        a[i+1] = 1 ;
                    }else{
                        a[i+1] = 0 ;
                        a[i].capnhat0( a[i+1].l1 , a[i+1].r1 );
                    }
                    if( a[i].l1 <= p && a[i].r1 >= p ){
                        in(n);
                        return ;
                    }
                    else{
                        No(i);
                        return;
                    }
                }
                else if( a[i].cnt == 2 ){
                    if(  x >= a[i+1].l0 && x <= a[i+1].r0  ){
                        if( x >= a[i+1].l1 && x <= a[i+1].r1 ){
                            dem = 1;
                        }
                    }
                }
                else{
                    No(i);
                    return ;
                }
            }
        }
        if( dem ==0 ){
            if( a[i].cnt == 2 ){
                ed = i ;
                dem =1 ;
            }
            else if( a[i].cnt == 0 ){
                a[i-1].capnhat1( a[i].l1 , a[i].r1 );
                ans[i] = 0;
            }
            else if( a[i].cnt == 1  ){
                a[i-1].capnhat0( a[i].l0 , a[i].r0 );
                ans[i] = 1 ;
            }
            else{
                No(i);
                return;
            }
            continue ;
        }
        else{
            dem = 0;
            int x = a[i].value ;
            if( a[i].cnt == 1 ){
                ans[i] = 1 ;
                a[i-1].capnhat0( a[i].l0 , a[i].r0 );
                if( x >= a[i+1].l1 && x <= a[i+1].r1  ){
                    a[i+1] = 0 ;
                }else{
                    a[i+1] = 1 ;
                    a[i-1].capnhat0( a[i+1].l0 , a[i+1].r0 );
                }
            }
            else if( a[i].cnt == 0 ){
                ans[i] = 0 ;
                a[i-1].capnhat1( a[i].l1 , a[i].r1 );
                if( x >= a[i+1].l0 && x <= a[i+1].r0  ){
                    ans[i+1] = 1 ;
                }else{
                    ans[i+1] = 0 ;
                    a[i-1].capnhat1( a[i+1].l1 , a[i+1].r1 );
                }
            }
            else if( a[i].cnt == 2 ){
                if(  x >= a[i+1].l0 && x <= a[i+1].r0  ){
                    if( x >= a[i+1].l1 && x <= a[i+1].r1 ){
                        dem = 1;
                    }else{

                    }
                }
            }
            else{
                No(i);
                return ;
            }
        }
    }
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
