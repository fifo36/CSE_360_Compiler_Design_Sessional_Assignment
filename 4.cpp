/*4. Write a C/C++ program that reads text from a file, then count and prints the number of
character exist in the inputted text file.*/

#include<bits/stdc++.h>
using namespace std;


int main(){
   fstream file_input;
   file_input.open("inputFile.txt");
   int countChar = 0;
   string str;
   while(getline(file_input, str)){
     for(int i = 0; str[i]; i++) countChar++;
   }
   cout<<"The number of characters are: "<<countChar<<endl;

   file_input.close();
   return 0;
}
