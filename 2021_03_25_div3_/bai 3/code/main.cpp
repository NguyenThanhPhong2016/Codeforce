#include <iostream>
#include <string>
using namespace std;
void solve(){
    string a ,b;
    cin>>a>>b;
    int maxbt = 0 ;
    for(int  i =0 ; i< a.size();i++){
        for(int j  = 0 ; j<b.size();j++){
            if( a[i] == b[j] ){
                int dem = 1;
                while( i+dem < a.size() && j +dem < b.size() && a[i+dem]==b[j+dem] ){
                    dem++;
                }
                if( dem > maxbt ) maxbt = dem  ;
            }
        }
    }
    cout<<a.size() + b.size() - 2 *maxbt<<endl;
}
int main()
{
    int t ;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
