#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int a[1000005];

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cin.ignore();
        string s;
        cin>>s;
        cin.ignore();
        stack<char> st;
        s = "@" + s;
        for(int i = 1; i<=n;i++){
            if(s[i] =='_'){
                if(st.empty()){
                    st.push('(');
                    s[i] = '(';
                }else{
                    st.pop();
                    s[i] = ')';
                }
            }else if(s[i]=='('){
                st.push('(');
            }else if( s[i]==')'){
                st.pop();
            }
        }
        long long cnt = 0;
        stack<pair<char,int>> tam;
        for(int i = 1; i<=n;i++){
            if(s[i]=='('){
                tam.push(make_pair('(',i));
            }else{
                pair<char,int> p = tam.top();
                cnt += -p.second + i;
                tam.pop();  
            }
        }
        cout<<cnt<<endl;
    }
}