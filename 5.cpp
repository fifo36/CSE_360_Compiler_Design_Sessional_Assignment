/*5.Write a C/C++ program that reads text from a file, then count and prints the number of
line exist in the inputted text file.*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    fstream file_input;
    file_input.open("inputFile.txt");
    int countLine = 0;
    string str;
    while(getline(file_input, str)) countLine++;

    cout<<"The number of lines are: "<<countLine<<endl;

    file_input.close();
    return 0;
}

