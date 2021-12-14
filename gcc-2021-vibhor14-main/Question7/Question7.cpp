#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
int primeF[MAX];
vector<bool> vis(MAX,false);
vector<int> parent(MAX,0);
vector<int> sz(MAX,1);
void initializeParent()
{
    int i;
    for(i=1;i<=MAX;++i)
        parent[i]=i;
}
int find_set(int v){
    if(v==parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}
void union_set(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(sz[a]<sz[b]){
            int temp = a;
            a=b;
            b=temp;
        }
        parent[b]=a;
        sz[a]+=sz[b];
    }
}
void sieve()
{   int i,j;
    for(i=1;i<=MAX;++i)
        primeF[i]=i;
    for(i=2;i*i<=MAX;++i){
        if(primeF[i]==i){
            for(j=i*i;j<=MAX;j+=i)
                primeF[j]=i;
        }
    }
}

void countStablePartitions(int &n, vector<int>& values) {
    sieve();
    initializeParent();
    int i,x,z,ans;
    for(i=0;i<n;i++){
        x = values[i];
        while(x!=1){
            z=primeF[x];
            while(x%z==0){
                x/=z;
            }
            union_set(values[i],z);
        }
    }
    z=0;
    for(i=0;i<n;i++){
        x = find_set(values[i]);
    if(vis[x] && x!=1)
        continue;
    vis[x]=true;
    z++;
    }
    ans =1;
    for(i=0;i<z;i++){
        ans = ans*2;
        ans = ans%1000000007;
    }
    ans = ans-2;
    if(ans==0){
        cout<<"NO"<<endl;
        cout<<ans;
    }
    else{
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> values(n);
   for (int i = 0; i < n; ++i) {
        cin >> values[i];
   }
   countStablePartitions(n, values);
   return 0;
}
