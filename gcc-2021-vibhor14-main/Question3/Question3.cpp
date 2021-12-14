#include <bits/stdc++.h>
using namespace std;

int portfolio_profit_maximisation(int &maxSum, vector<int> &a, vector<int> &b) {
    //write your code here
    int i=0,j=0;
    int count =0;
    long long rs=0;
    while(rs<=maxSum && i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
            rs+=a[i];
            if(rs>maxSum){
                return count;
            }
            i++;
            count++;
        }else{
            rs+=b[j];
            if(rs>maxSum){
                return count;
            }
            j++;
            count++;
        }
    }
    while(rs<=maxSum && i<a.size()){
        rs+=a[i];
        if(rs>maxSum){
            return count;
        }
        i++;
        count++;
    }
    while(rs<=maxSum && j<b.size()){
        rs+=b[j];
        if(rs>maxSum){
            return count;
        }
        j++;
        count++;
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int result = portfolio_profit_maximisation(x, a, b);
    cout << result;
    return 0;
}