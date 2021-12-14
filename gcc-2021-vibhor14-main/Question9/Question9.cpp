#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int solve(int c, int b,vector< vector<int> > &time, vector<bool> &vis,int cs,int temp,int &ans){
    if(cs>=c){
        return temp;
    }
    if(b==time.size()-1){
        for(int i=cs;i<c;i++){
            temp +=time[b][i];
        }
        return temp;
    }
    for(int i=0;i<time.size();i++){
        if(vis[i]==true){
            continue;
        }
        vis[i]==true;
        int ct=0;
        for(int j=cs;j<c;j++){
            ct+=time[i][j];
            ans = min(ans,solve(c,b+1,time,vis,j+1,temp+ct,ans));
        }
        vis[i]=false;
    }
    return ans;
}
int bankersAndClients(int &c, int &b,vector< vector<int> > &time) {
    int ans = INT_MAX;
    if(b==1){
        int res=0;
        for(int i=0;i<c;i++){
            res+=time[0][i];
        }
        return res;
    }
    vector<bool> vis(b,false);
    solve(c,0,time,vis,0,0,ans);
    return ans;


}
int main(){
    int b,c;
    cin >> c>>b;
    int answer;
    vector<vector<int>> time(b,vector<int>(c));
    for(int i = 0; i < b; i++){
        
        for(int j = 0;j < c;j++){
          cin>>time[i][j];
        }
    }
	answer = bankersAndClients(c,b,time);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line
        
    return 0;
}