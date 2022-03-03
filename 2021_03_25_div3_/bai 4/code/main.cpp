#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ;cin>>n;
    map<int , int > s;
    for(int i = 0,x ; i< n ;i++){
        cin>>x;
        s[x]++;
    }
    int maxbt = 0;
    for( auto x : s ){
        if( x.second > maxbt ) maxbt = x.second;
    }
    if( n%2 ==0 ){
        if( maxbt <= n /2 ) cout<<0<<endl;
        else{
            cout<<2*maxbt - n <<endl;
        }
    }
    else{
        if( maxbt <= (n-1)/2  ) cout<<1<<endl;
        else{
            cout<< 2*maxbt - n<<endl;
        }
    }
}
int main()
{
    int t ;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
