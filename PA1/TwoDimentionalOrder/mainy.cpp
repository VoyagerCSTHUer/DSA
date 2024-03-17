#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Tuple{
public:
    int a;
    int b;
    int c;
    int id;
};

vector<Tuple> set;
vector<long long int> dp;
vector<Tuple> deduplicatedSet;

bool cmpb(Tuple A, Tuple B){
    if(A.b <= B.b)return true;
    return false;
}

void merge(vector<Tuple> set,int lo,int mi,int hi){
    sort(set.begin()+lo,set.begin()+mi,cmpb);
    sort(set.begin()+mi,set.begin()+hi,cmpb);
    int initialMi = mi;
    long long int maxF = 0;
    while(lo < initialMi && mi < hi){
        if(cmpb(set[lo],set[mi])){
            maxF = max(maxF,dp[set[lo].id]);
            dp[set[mi].id] = max(dp[set[mi].id],maxF+deduplicatedSet[mi].c);
            lo++;
        }
        else{
            mi++;
        }
    }
    while(mi < hi){
        dp[set[mi].id] = max(dp[set[mi].id],maxF);
        mi++;
    }
}

void dpmerge(vector<Tuple> set,int lo,int hi){
    if ( hi - lo < 2 ) return; //单元素区间自然有序，否则...
    int mi = ( lo + hi ) / 2; //以中点为界
    dpmerge( set, lo, mi ); 
    merge( set, lo, mi, hi ); //归并
    dpmerge( set, mi, hi ); //前缀、后缀分别排序
}

bool cmp(Tuple A, Tuple B){
    if(A.a < B.a) return true;
    if(A.a == B.a && A.b <= B.b) return true;
    return false;
}

int main(){
    int m;
    cin >> m;
    set.resize(m);
    dp.resize(m);

    int cnt = 0;
    for(int i = 0; i < m; i++){
        int tem1, tem2, tem3;
        cin >> tem1 >> tem2 >> tem3;
        if(tem3 > 0){
            set[cnt].a = tem1;
            set[cnt].b = tem2;
            set[cnt].c = tem3;
            cnt++;
        }
    }

    sort(set.begin(), set.begin() + cnt, cmp);

    vector<bool> dedup(cnt);
    for(int i=0;i<cnt;i++){
        if(0<i && (set[i-1].a == set[i].a) && (set[i-1].b == set[i].b)){
            set[i].c += set[i-1].c;
            dedup[i-1] = true;
        }
    }

    for(int i=0;i<cnt;i++){
        if(!dedup[i]) deduplicatedSet.push_back(set[i]);
    }

    int sizeofDedupSet = deduplicatedSet.size();

    for(int i = 0; i < sizeofDedupSet; i++){
        deduplicatedSet[i].id = i;
        dp[i] = set[i].c;
    }

    dpmerge(deduplicatedSet,0,deduplicatedSet.size());

    long long int ans = 0;
    for(int i = 0; i < sizeofDedupSet; i++){
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}
