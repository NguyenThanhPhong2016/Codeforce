#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
//  sort(v.begin(), v.end(), greater<int>());
//
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

void solve(){
    int n ;cin>>n;
    int a[n];
    int dem = 0;
    char x;
    for(int i = 0 ; i < n ;i++){
        cin>>x;
        if( x == '*' ){
            a[i] =1;
            dem++;
        }
        else a[i] = 0;
    }
    if( dem==1 || dem == 0 ){
        cout<<0<<endl;
        return ;
    }
    int b[n];
    int c[n];
    int trai = 0;
    for(int i = 0 ; i<n;i++){
        if( a[i] ==1 ){
            trai++;
            b[ i ] = trai;
        }
        else{
            b[i] = trai;
        }
    }
    int phai = 0 ;
    for(int i = n-1 ; i>=0;i--){
        if( a[i] ==1 ){
            phai++;
            c[ i ] = phai;
        }
        else{
            c[i] = phai;
        }
    }
    int i = 0 , j = n -1;
    int ans = 0;
    while( i<n && a[i] ==0 ) i++;
    while( i+1<n && b[i] != b[i+1] ) i++;
    while( j>=0 && a[j] ==0  ) j--;
    while( j-1>=0 && c[j] != c[j-1]  ) j--;
    while( i<j ){
        if( b[i] > c[j] ){
            ans += c[j];
            j--;
            while( j-1>=0 && c[j] != c[j-1]  ) j--;
            continue;
        }
        else{
            ans += b[i];
            i++;
            while( i+1<n && b[i] != b[i+1] ) i++;
            continue;
        }
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
