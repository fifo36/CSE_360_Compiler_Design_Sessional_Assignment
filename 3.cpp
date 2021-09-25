//3. Write a C/C++ program to test whether a given identifier is valid or not

#include<iostream>
using namespace std;


int main(){
    string str;
    cout<<"Enter your input: ";
    getline(cin, str);
    bool isIdentifier = 1; //assuming as an identifier
    char ch = str[0];
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_'){
       for(int i = 0; i < str.size(); i++){
           ch = str[i];
           if(!((ch >= 'a' && ch <= 'z') || (str [i] >= 'A' && ch <= 'Z')
              || ch == '_' || (ch >= '0' && ch <= '9'))){
              isIdentifier = 0; /// invalid char found
           }
       }
    }
    else isIdentifier = 0;
    if(isIdentifier) cout<<"Valid Identifier"<<endl;
    else cout<<"Not an Identifier"<<endl;
}
