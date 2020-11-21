#include<iostream>
#include <string>
#include<stack>


using namespace std;
stack<char> st;

bool isMatch(char c){
    if(st.top() =='[' && c==']')
        return true;
    if(st.top() =='{' && c=='}')
        return true;
    if(st.top() =='(' && c==')')
        return true;
    return false;
}

bool paranthesis_matching(string s){

    int len= s.length();
    for(int i=0; i<len; i++){
        if(s[i]=='[' || s[i]=='{' || s[i]=='(')
            st.push(s[i]);

        if(s[i]==']' || s[i]=='}' || s[i]==')'){

            if(st.empty() || isMatch(s[i])==false)
                return false;
            else 
                st.pop();
        }
    }
    return(st.empty()? true:false);
}

int main()
{
    string exp;
    cin>>exp;
    if(paranthesis_matching(exp))
        cout<<"Success!\n";
    else 
    cout<<"Paranthesis not matching!";

}
