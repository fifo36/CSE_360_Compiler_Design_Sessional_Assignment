/*8.Imagine the syntax of a programming language construct such as while-loop --
while ( condition )
begin
statement ;
:
end
where while, begin, end are keywords; condition can be a single comparision expression
(such as x == 10, etc.); and statement is the assignment to a location the result of a single
arithmatic operation (eg., a = 5 * b).
Write a C/C++ program that verifies whether the input follows the above syntax.*/

#include<bits/stdc++.h>
using namespace std;

vector<string>vec;
int fun(string s){
    if(s.back()!=';') return 0;
    string one="",two="",three="",four="",five="";
    int i=0;
    while(s[i]!=' ' && i<s.size() && (isalpha(s[i]) || isalnum(s[i]))){
        one+=s[i];
        i++;
    }
    while(i<s.size() && s[i]==' '){
        i++;
    }

    while((s[i]=='=' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='`' || s[i]=='|' || s[i]=='^' || s[i]=='&') && i<s.size()){
        two+=s[i];

        i++;
    }
    while(i<s.size() && s[i]==' '){
        i++;
    }
    while(s[i]!=' ' && i<s.size() && (isalpha(s[i]) || isalnum(s[i]))){
        three+=s[i];
        i++;
    }
    while(i<s.size() && s[i]==' '){
        i++;
    }
    while(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='`' || s[i]=='|' || s[i]=='^' || s[i]=='&'){
        four+=s[i];
        i++;
    }
    while(i<s.size() && s[i]==' '){
        i++;
    }
    while(s[i]!=' ' && i<s.size()-1 && (isalpha(s[i]) || isalnum(s[i]))){
        five+=s[i];
        i++;
    }


    int num_one=1;
    int num_two=1;
    if(four.size()==0 && five.size()==0 && two!="=") return 0;
    if(isalnum(three[0])){
        for(int i=0;i<three.size();i++){
            if(isalpha(three[i])) num_one=0;;
        }
    }
    if(isalnum(five[0])){
        for(int i=0;i<five.size();i++){
            if(isalpha(five[i])) num_two=0;;
        }
    }

    if(one.size()  && (!isalpha(one[0]) && one[0]!='_')){
        return 0;
    }

    if(three.size() && num_one==0 && (!isalpha(three[0]) && three[0]!='_')){
        return 0;
    }

    if(five.size() && num_two==0 && (!isalpha(five[0]) && five[0]!='_')){
        return 0;
    }

    if(four.size()>1) return 0;
    if(two.size()>2) return 0;
    if(two.size()==2 && (four.size()!=0 || five.size()!=0)) return 0;
    return 1;
}
int check_con(string s)
{
    string one="",two="",three="";
    if(s.back()!=';') return 0;
    int i=0;
    while(s[i]!=' ' && i<s.size() && (isalpha(s[i]) || isalnum(s[i]))){
        one+=s[i];
        i++;
    }
    while(i<s.size() && s[i]==' '){
        i++;
    }
    while(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='`' || s[i]=='|' || s[i]=='^' || s[i]=='&'){
        two+=s[i];
        i++;
    }
    while(i<s.size() && s[i]==' '){
        i++;
    }
    while(s[i]!=' ' && i<s.size() && (isalpha(s[i]) || isalnum(s[i]))){
        one+=s[i];
        i++;
    }

    if(three.size()==0 && two.size()==0) return 1;
    if(three.size()==0 && two.size()!=0) return 0;
    if(one.size() && (!isalpha(one[0]) || one[0]!='_')){
        return 0;
    }
    if(three.size() && (!isalpha(three[0]) || three[0]!='_')){
        return 0;
    }
    if(two.size()!=1) return 0;
    if(two!="+" || two!="-" || two!="*" || two!="/") return 0;
    return 1;
}
int main()
{
    while(1){
        string s,str="";
        cin>>s;
        vec.push_back(s);
        if(s=="end") break;
    }
    int ok=1;
    string first=vec[0];

    string keyword_while="",open_b="",close_b="",cond_bef="",con_after="",cond="";
    int i=0;
    while(i<first.size() && i<5){
        keyword_while+=first[i];
        i++;
    }
    while(i<first.size() && first[i]==' '){
        i++;
    }
    if(i<first.size()){
        open_b+="(";
        i++;
    }
    while(i<first.size() && first[i]==' '){
        i++;
    }
    while(isalpha(first[i]) || isalnum(first[i])){
        cond_bef+=first[i];
        i++;
    }
    while(i<first.size() && first[i]==' '){
        i++;
    }
    if(first[i]=='!' || first[i]=='>' || first[i]=='<' || first[i]=='=') {
            cond+=first[i];
    }
    if(first[i]==' ') i++;
    else if(first[i]=='=') {
        cond+=first[i];
        i+=2;
    }
    while(i<first.size() && first[i]==' '){
        i++;
    }
    while(isalpha(first[i]) || isalnum(first[i])){
        cond_bef+=first[i];
        i++;
    }
    while(i<first.size() && first[i]==' '){
        i++;
    }
    if(i<first.size()){
        close_b+=")";
        i++;
    }

    if(keyword_while=="while" &&  open_b=="(" && close_b ==")" && (cond!=">" || cond!="<" || cond!="!=" || cond!="<=" || cond!=">=" || cond!="==")) ok=1;
    else ok=0;

    int ck=check_con(cond_bef);

    if(ck==0) ok=0;
    ck=check_con(con_after);
    if(ck==0) ok=0;

    string second=vec[1];
    for(int i=2;i<vec.size()-2;i++){
        int ck=fun(vec[i]);
        if(ck==0) ok=0;
    }

    string second_last=vec[vec.size()-2];
    if(second_last!=":") ok=0;

    string last=vec.back();
    if(last!="end") ok=0;
    if(ok) cout<<"the input follows the above syntax. "<<endl;
    else{
        cout<<"the input doesnot follows the above syntax. "<<endl;
    }
}

