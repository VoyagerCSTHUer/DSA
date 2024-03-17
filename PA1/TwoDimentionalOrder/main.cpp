#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Tuple{
public:
    int a;
    int b;
    int c;
};

bool cmp(Tuple A,Tuple B){
    if(A.a<B.a)return true;
    if(A.a==B.a && A.b<=B.b)return true;
    return false;
}

int main(){
    int m;
    cin>>m;
    vector<Tuple> set;
    set.resize(m);
    int cnt=0;
    int tem1,tem2,tem3;
    for(int i=0;i<m;i++){
        cin>>tem1>>tem2>>tem3;
        if(tem3>0){
            set[cnt].a = tem1;
            set[cnt].b = tem2;
            set[cnt].c = tem3;
            cnt++;
        }
    }
    sort(set.begin(),set.end(),cmp);

    int i = -1; //锟斤拷锟斤拷前锟剿匡拷始
    while ( ++i < int(set.size()) - 1 ) { //锟斤拷前锟斤拷锟斤拷锟揭�
        int j = i + 1; //assert: _elem[0, i]锟叫诧拷锟斤拷锟截革拷元锟斤拷
        while ( j < int(set.size()) )
        if ( set[i].c == set[j].c ) {
            set[i].c += set[j].c;
            set.erase ( set.begin() + j ); //锟斤拷锟斤拷同锟斤拷锟斤拷删锟斤拷锟斤拷锟斤拷
        }
        else j++; //锟斤拷锟斤拷锟斤拷扫锟斤拷
    }

    vector<long long int> dp;
    for(int i=0;i<int(int(set.size()));i++){
        dp.push_back(set[i].c);
    }
    for(int j=0;j<int(set.size());j++){
        for(int k=j-1;k>=0;k--){
            if(set[k].b <= set[j].b){
                dp[j] = max( dp[j], dp[k] + set[j].c);
            }
        }
    }
    long long int ans = 0;
    for(int i=0;i<int(set.size());i++){
        ans = max(ans, dp[i]);
    }
    cout<<ans;
    return 0;
}