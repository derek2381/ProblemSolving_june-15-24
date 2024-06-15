// problem link
// https://codeforces.com/problemset/problem/1097/A


#include <bits/stdc++.h>

using namespace std;

int main(){
    string str1;
    cin >> str1;

    set<char> st;
    for(int i = 0; i <5;i++){
        string str;
        cin >> str;
        st.insert(str[0]);
        st.insert(str[1]);
    }

    if(st.find(str1[0]) != st.end() || st.find(str1[1]) != st.end()){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}
