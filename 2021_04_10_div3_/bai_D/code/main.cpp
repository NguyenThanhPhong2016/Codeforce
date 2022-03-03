#include    <bits/stdc++.h>
#define fi  first
#define se  second
#define ll  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define int ll
using namespace std;
void in( int b[],ll k,ll x , int n ){
    if( k==x ){
        int dem =2 ;
        for(int i = 0 ;i <n;i++){
            if( dem >0 ){
                if(b[i] == k ){
                    dem--;
                }
                else{
                    cout<<b[i]<<" ";
                }
            }
            else{
                cout<<b[i]<<" ";
            }
        }
    }
    else{
        int dem1 = 1;
        int dem2 = 1;
        for(int i = 0 ;i<n;i++){
            if( dem1 >0  ){
                if( b[i] == k ) {dem1--;continue;}
                else{
                    if( dem2 >0 ){
                        if( b[i] == x ) {dem2--;continue;}
                        else{
                            cout<<b[i]<<" ";
                        }
                    }
                    else{
                        cout<<b[i]<<" ";
                    }

                }
            }
            else{
                if( dem2 >0 ){
                    if( b[i] == x ) {dem2--;continue;}
                    else{
                        cout<<b[i]<<" ";
                    }
                }
                else{
                    cout<<b[i]<<" ";
                }
            }
        }
    }
    cout<<"\n";
}
void solve(){
    int n ;cin>>n ;
    int b[n+2];
    int maxbt1 = 0;
    int maxbt2 = 0;
    ll sum = 0;
    for(int i =0 ; i < n+2;i++){
        cin>>b[i];
        sum += b[i];
        if( b[i] > maxbt1 ){
            maxbt2 = maxbt1 ;
            maxbt1 = b[i];
        }
        else if( b[i] > maxbt2 ){
            maxbt2 = b[i];
        }
    }
    ll k, x ;
    ll h = 0ll + maxbt2*2 + maxbt1 ;
    if( h == sum  ){
        in( b,maxbt2 , maxbt1 , n+2  );
    }
    else{
        k = maxbt1 ;
        x = sum - 2*maxbt1;
        if( x<=0 ){
            cout<<-1<<endl;
            return;
        }
        else{
            int dem = 1;
            if( x==k ) dem++;
            for(int i = 0 ; i < n+2;i++){
                if( b[i] == x ){
                    dem--;
                    if(dem==0) {
                        in( b, k ,x ,n+2   );
                        return;
                    }
                }
            }
            cout<<-1<<endl;
            return;
        }
    }
}
signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
