#include <string>
#include <iostream>
#include <map>
#include <set>
using namespace std;


int main(){
    int t; cin>>t;
    while(t--){
        string s;
        cin>>s;
        cin.ignore();
        set<char> se;
        for(int i = 0; i<s.size(); i++){
            se.insert(s[i]);
        }
        char x = 'a';
        for(int i = 61; i<=122; i++){
            if(se.find(x)==se.end()){
                break;
            }else x = x + 1;
        }
        if(s.size()==1){
            s.push_back(x);
            cout<<s<<endl;
            continue;
        }
        string tam;
        tam.push_back(x);
        int flag = 0;
        for(int i = 1; i< s.size(); i++){
            if(s[i]==s[i-1]){
                s.insert(i,tam);
                flag  =1;
                break;
            }
        }
        if(flag==0) s.push_back(x);
        cout<<s<<endl;
    }
}