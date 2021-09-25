/*1. Write a C/C++ program that reads text from a file and prints on the terminal each input 
line, preceded by the line number. The output will look like -
1 This is the first trial line in the file,
2 and this is the second line.
Try the problem once using fgetc() function and once using fgets() function for reading 
the input. Why is fread() not suitable for this purpose?*/

//Coded, considering empty string as a valid input line.

#include<bits/stdc++.h>
using namespace std;

void using_fgetc(){
    //reading input file
    FILE *file = fopen("inputFile.txt", "r");

    int lineNo = 1;
    char currentChar = fgetc(file);

    cout<<lineNo++<<" "<<currentChar;
    bool isNewLine = 0;
    if(currentChar == '\n') isNewLine = 1;

    while((currentChar = fgetc(file)) != EOF){
	    if(isNewLine) cout<<lineNo++<<' ';
        cout<<currentChar;
        if(currentChar == '\n') isNewLine = 1;
        else isNewLine = 0;
	}

	fclose(file);   //closing file.
}

void using_fgets(){

    //reading input file
    FILE *file = fopen("inputFile.txt" , "r");
    int lineNo = 1, maxStringLength = 1000;
    char str[maxStringLength];
    while(fgets(str, maxStringLength, file) != NULL){
        //printing output
        cout<<lineNo++<<" "<<str;
    }

    fclose(file);   //closing file.
}

int main(){
    cout<<"Output: Using fgetc()\n";
    using_fgetc();
    cout<<"\nOutput: Using fgets()\n";
    using_fgets();
}
