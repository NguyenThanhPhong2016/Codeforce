#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ;
    cin>>n;
    int a[n+1];
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i];
    }
    int b[n+1];
    int c[n+1];
    for(int i = 1 ; i<= n ; i++){
        b[i] = 0 ;
        c[i] = 0;
    }
    for(int i =1 ;i<=n;i++){
        b[ a[i] ] = 1;
        c[ a[i] ] = 1;
    }
    set<int> b1;
    set<int> c1 ;
    for(int i = 1 ; i<a[1];i++){
        b1.insert(i);
        c1.insert(i);
    }
    int kqmin[n+1];
    int kqmax[n+1];
    kqmin[1] = a[1];
    kqmax[1] = a[1];
    b[ a[1] ] = 1;
    c[ a[1] ] =1 ;
    int minbt = 1;
    int maxbt = n;
    for(int i = 2 ; i<= n ;i++){
        if( a[i] == a[i-1] ){
            auto minbt1 = b1.begin();
            kqmin[i] = *minbt1;
            b1.erase( minbt1 );
        }
        else{
            for(int j = a[i-1]+1 ; j < a[i] ; j++){
                b1.insert(j);
            }
            kqmin[i] = a[i];
        }
    }
    for(int i = 1 ; i<= n ; i++){
        cout<<kqmin[i]<<" ";
    }
    cout<<endl;
    for(int i = 2 ; i<= n ;i++){
        if( a[i] == a[i-1] ){
            auto maxbt1 = c1.end();
            maxbt1--;
            kqmax[i] = *maxbt1;
            c1.erase( maxbt1 );
        }
        else{
            kqmax[i] = a[i];
            for(int j = a[i-1]+1;j<a[i];j++){
                c1.insert(j);
            }
        }
    }
    for(int i = 1 ; i<= n ; i++){
        cout<<kqmax[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int t ;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
