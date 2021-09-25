//2. Write a C/C++ program to identify whether a given input line is a comment or not.

#include<iostream>
using namespace std;


int main(){
   string inputLine;
   getline(cin, inputLine);
   bool isComment = 0;
   int lineLength = inputLine.size();

    if(lineLength >= 2 && inputLine[0] == '/' && inputLine[1] == '/') isComment = 1;
    else if(lineLength > 3 && inputLine[0] == '/' && inputLine[1] == '*'
    && inputLine[lineLength-1]=='/' && inputLine[lineLength-2] == '*') isComment = 1;

    if(isComment) cout<<"Comment"<<endl;
    else cout<<"NOT a Comment"<<endl;
}
