#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long double ld;
signed main()
{
    int t ;cin>>t ;
    int a , b;
    while(t--){
        int n;cin>>n;
        vector<int> x;
        vector<int> y;
        for(int i =0 ;i< 2*n;i++){
            cin>>a>>b;
            if(a==0){
                x.push_back(abs(b));
            }
            else{
                y.push_back(abs(a));
            }
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        ld kq = 0;
        for( int i =0;i<x.size();i++ ){
            kq = kq + sqrt( x[i]*x[i] + y[i]*y[i] ) ;
        }
        std::cout << std::setprecision(20) << kq << '\n';
    }
    return 0;
}
