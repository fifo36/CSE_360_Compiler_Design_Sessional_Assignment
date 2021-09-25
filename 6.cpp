/*6.Write a C/C++ program that reads text from a file, then delete the existing comment and
save the output text file (without comment). Also count and print the number of deletion.*/

#include<bits/stdc++.h>
using namespace std;


int main(){
    FILE *file_input, *file_output;
    file_input = fopen("inputFile.txt","r");
    file_output = fopen("outputFile.txt","w");

    int maxStringLength = 1000, commentCount = 0;
    char inputLine[maxStringLength];

    while(fgets(inputLine, maxStringLength, file_input) != NULL){

        int lineLength = strlen(inputLine);
        if(lineLength > 1 && inputLine[0] == '/' && inputLine[1] == '/') commentCount++;
        else if(lineLength > 3 && inputLine[0] == '/' && inputLine[1] == '*'
                && inputLine[lineLength-1]=='/' && inputLine[lineLength-2] == '*') commentCount++;
        else fputs(inputLine, file_output);
    }

    cout<<"Total Comment Count: "<<commentCount<<'\n';
}
