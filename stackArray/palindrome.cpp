#include <iostream>
#include <iostream>
#include "stack.h"
#include <string>

using namespace std;

string getLine();
void perform(string line);
string trimAndNormalize(string line);

int main()
{
    string line;
    while((line = getLine()) != "") // runs if the line is not empty
    {
        perform(line);
    }
    return 0;
}

// gets the line
string getLine()
{
    string line;
    cout<<"Input: ";
    getline(cin, line);
    return line;
}


void perform(string line)
{
    stack<char> mystack(line.size()); // a stack of characters
    string normalized, reversed;
    normalized = trimAndNormalize(line);
    for(unsigned int i = 0; i < normalized.size(); i++)
    {
        mystack<<normalized[i];
    }
    while(!mystack.empty())
        reversed += mystack.pop();
    string isNot = reversed == normalized ? " is " : " is not ";
    cout<<line<<isNot<<"a palindrome"<<endl;

}


string trimAndNormalize(string line)
{
    string blank = "";
    for(unsigned int i = 0; i < line.size(); i++)
    {

        if(isalpha(line[i]))
        {
            blank+=toupper(line[i]);
        }
        else if (line[i] == ' ' || ispunct(line[i]))
        {

        }
        else
        {
            blank+=line[i];
        }
    }


    return blank;
}





/*
Input: ana band
ana band is not a palindrome
Input: Ana nab a banana.
Ana nab a banana. is a palindrome
Input:
Press <RETURN> to close this window...


 */
