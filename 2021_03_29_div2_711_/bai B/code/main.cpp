#include <bits/stdc++.h>

using namespace std;
int kq ;
int log2(int a){
    int sum =1 ,dem = 0;
    while( sum < a ){
        dem++;
        sum = sum*2;
    }
    return dem ;
}
void chay( int x ,int s[],int b[],int temp){
    if( s[x] <= b[x] ){
        b[x] -= s[x];
        int h = x-1;
        while( h >=0 && s[h] ==0 ){
            h--;
        }
        if( h == -1 ){
            kq++;
            return;
        }
        chay( h , s ,b ,1);
    }
    else{
        if( x!=0 ){
            if( b[x] !=0  ) temp = 1;
            s[x] -= b[x];
            b[x] = 0;
            s[x-1] += 2*s[x];
            chay(x-1,s,b,temp);
        }
        else{
            if( b[x] !=0  ) temp = 1;
            s[x] -= b[x];
            b[x] = 0;
            if(temp ==1) kq++;return;
        }
    }
}
void solve(){
    kq = 0;
    int s[31];
    for(int i = 0 ; i<= 30 ; i++){
        s[i] = 0;
    }
    int n,w;cin>>n>>w;
    int k = w;
    int dem = 0;
    while( w>0 ){
        s[dem] = w%2;
        w = w/2;
        dem++;
    }
    int b[31];
    for(int i  = 0 ;  i<= 30 ; i++){
        b[i] = 0;
    }
    for(int i = 0,x ; i < n; i++){
        cin>>x;
        x = log2(x);
        b[x]++;
    }
    s[dem] = 0;
    for(int i = dem-1 ; i>=0 ;i--){
        s[i] += s[i+1]*2;
        s[i+1] = 0;
        int c[31];
        for(int j = 0 ; j<= 30 ; j++){
            c[j] = s[j];
        }
        chay(i,c,b,0);
        if( b[i] >0 ) i++;
    }
    cout<<kq<<endl;
    kq = 0;
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();

    }
}
