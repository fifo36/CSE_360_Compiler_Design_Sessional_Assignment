/*7.Write a C/C++ program that reads text from a file, then delete the existing tabs (spaces)
and new line and save the output text file. Also count and print the number of deletion.*/

#include<bits/stdc++.h>
using namespace std;


int main(){
    FILE *file_input, *file_output;
    file_input = fopen("inputFile.txt", "r");
    file_output = fopen("outputFile.txt", "w");
    char ch;
    int deletionCount = 0;

    while((ch = fgetc(file_input)) != EOF){
        if(ch == ' ' || ch == '\n') deletionCount++;
        else fputc(ch, file_output);
    }
    cout<<"Total number of deletion is "<<deletionCount<<endl;

    fclose(file_input);
    fclose(file_output);
    return 0;
}
