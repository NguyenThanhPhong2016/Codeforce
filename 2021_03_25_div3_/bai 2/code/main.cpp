#include <bits/stdc++.h>

using namespace std;
void solve(){
    int k,n;cin>>n>>k;
    string a ;
    cin>>a;
    int dem = 1;
    stack<int> s;
    for(int i = n-1 ; i >=0;i--){
        if( a[i] =='*' ){
            s.push(i);
        }
    }
    if( s.size() == 1 ) {cout<<1<<endl;return;}
    int x = s.top();
    int y;
    s.pop();
    while( s.size() != 0 ){
        while( s.size() !=0 && s.top() <= x + k ){
            y=s.top();
            s.pop();
        }
        dem++;
        x = y;
    }
    cout<<dem<<endl;

}
int main()
{
    int t ;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
