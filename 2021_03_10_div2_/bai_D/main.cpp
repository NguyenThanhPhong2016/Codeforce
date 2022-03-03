#include <bits/stdc++.h>

using namespace std;
vector<int> bt;
struct m{
    int u;
    vector<int> v ;
    int solan;
};
int main()
{
    int n ;cin>>n;
    int a[n+1];
    for(int i =0 ; i<n ;i++){
        cin>>a[i];
    }
    int temp = 1 ;
    int dem = 1;
    for(int i = 0 ; i<= n-1;i++){
        if(i==n-1){
            bt.push_back(dem);
            break;
        }
        if(temp == 1){
            if( a[i] < a[i+1] ){
                dem++;
            }
            else{
                bt.push_back(dem);dem =2;temp =0;
            }
        }
        else{
            if( a[i] > a[i+1] ){
                dem++;
            }
            else{
                bt.push_back(dem);dem = 2;temp =1;
            }
        }
    }
    m maxbt ;
    maxbt.u = 0;
    maxbt.solan =1 ;
    maxbt.v.clear();
    for(int i =0 ;i< bt.size() ; i++){
        if( bt[i] > maxbt.u ){
            maxbt.v.clear();
            maxbt.u = bt[i];
            maxbt.v.push_back(i);
            maxbt.solan =1;
        }
        else{
            if( bt[i] == maxbt.u ){
            maxbt.v.push_back(i);
            maxbt.solan++;
            }
        }
    }
    if(maxbt.solan >=3){
            cout<<0;exit(0);
        }
    if( maxbt.solan ==2 && maxbt.u%2 ==1 ){
        if( maxbt.v[0]%2 ==0 &&  maxbt.v[0] +1 == maxbt.v[1]  ){
                cout<<1;exit(0);
        }
        cout<<0;exit(0);
    }
    cout<<0;
    return 0;
}
