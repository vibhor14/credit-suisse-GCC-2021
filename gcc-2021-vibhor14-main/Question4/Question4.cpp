#include<bits/stdc++.h>
using namespace std;
void ngr(int &n, vector<int>& values, vector<int> &v2,vector<int> &v){
    stack <pair<int,int>> st;
    stack <pair<int,int>> st2;
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            v2.push_back(-1);
        }
        if(!st.empty()&&st.top().first>=values[i]){
            v2.push_back(st.top().second);
        }
        
        else if(!st.empty()&& st.top().first<values[i]){
            while(st.size()>0 && st.top().first<values[i]){
                st.pop();
            }
            if(st.size()>0){
                v2.push_back(st.top().second);
            }
            else{
                v2.push_back(-1);
            }
        }
        st.push({values[i],i});
        //-----------for st2 -----------------------------------------
        if(st2.empty()){
            v.push_back(-1);
        }
        if(!st2.empty()&&st2.top().first>=values[n-i-1]){
            v.push_back(st2.top().second);
        }
        else if(!st2.empty()&& st2.top().first<values[n-i-1]){
            while(st2.size()>0 && st2.top().first<values[n-i-1]){
                st2.pop();
            }
            if(st2.size()>0){
                v.push_back(st2.top().second);
            }
            else{
                v.push_back(-1);
            }
        }
        st2.push({values[n-i-1],n-i-1});
        
    }
    //reverse(v2.begin(),v2.end());
}
int totalPairs(int &n, vector<int>& values) {
    vector<int> v;
    vector<int> v2;
    ngr(n,values,v2,v);
    int res = n-1;
    for(int i=0;i<n;i++){
        if(v[i]!=i-1 && v[i]!=-1){
            res++;
        }
    }
    for(int i=0;i<n;i++){
        if(v2[n-i-1]!=i+1 && v2[n-i-1]!=-1){
            res++;
        }
    }
    
    return res;
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
    // Do not remove below line
    cout <<  totalPairs(n, values)<< endl;
    // Do not print anything after this line
        
    return 0;
}