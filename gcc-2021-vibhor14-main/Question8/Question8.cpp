#include <bits/stdc++.h>

using namespace std;
int solve(int &n, int k, int d,int currday, int &m, vector<int> &returns, int i,int temp){
    
    if(i>=returns.size()-k && k!=0){
        return 0;
    }
    if(i>=returns.size() && k==0){
        return temp;
    }
    int multiplier=1;
    if(currday<=0){
        multiplier = 1;
    }
    else{
        multiplier = m;
    }
    if(k==0){
        return solve(n,k,d,currday-1,m,returns,i+1,temp+returns[i]*multiplier);
    }
    //take, not take
    else{
        return max (solve(n,k-1,d,d,m,returns,i+1,temp+0),  solve(n,k,d,currday-1,m,returns,i+1,temp+returns[i]*multiplier) );
    }
}
int calculateMaximizedReturns(int &n, int &k, int &d, int &m, vector<int> &returns) {
    if(k>=n || n<=0){
        return 0;
    }
    return solve(n,k,d,0,m,returns,0,0);
    return -1;
}

vector<string> split(const string& str, char delim) {
    vector<string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
}

vector<int> splitStringToInt(const string& str, char delim) {
    
    vector<int> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(stoi(str.substr(start, end - start)));
    }
    return strings;
}

void printVector(vector<int> vec) {
    for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string firstLine;
    getline(cin, firstLine);

    vector<int> firstLineVec = splitStringToInt(firstLine, ' ');
    int n = firstLineVec[0];
    int k = firstLineVec[1];
    int d = firstLineVec[2];
    int m = firstLineVec[3];

    string returns;
    getline(cin, returns);

    vector<int> returnsVec = splitStringToInt(returns, ' ');

    int result = calculateMaximizedReturns(n, k, d, m, returnsVec);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}