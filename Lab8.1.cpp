//File Name: health.cpp 
//Author: Tess Neau
//Email Address: neaut@kenyon.edu
//Assignment Number: 12
//Description: This program decrypts the message ":mmZ\dxZmx]Zpgy" while knowing how it was encrypted. 
//Last Changed: November 8th 2016

#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

char decryptChar(char encryptedChar, int key);
// Precondition: encryptedChar is any character from the ASCII Character Set and key is between 1 and 100
// Postcondition: the "decrypted" character is returned.
string decryptString (string encryptStr, int key); // uses key to decrypt encryptedStr, returning the decrypted string. (will use decryptChar above)
// Precondition: encryptStr is any string which contains characters from the ASCII Character Set and key is between 1 and 100
// Postcondition:  the "decrypted" string is returned.

int main( )
 {
    string encryptedString;
    int keyCount(1), key(1);
    
    cout << "Please enter an encrypted code: ";
    getline(cin,encryptedString);
    cout << endl << "Your Encrypted Code: " << encryptedString << endl << endl;
    
    while (key < 101)
    {
        cout << "Key " << keyCount << ": " << decryptString(encryptedString,key) << endl;
        
        key++;
        keyCount++;
    }
    
    cout << endl
         << "The valid key is Key 88 : " << decryptString(encryptedString,88) << endl;
    
    return 0;  
}

char decryptChar(char encryptedChar, int key)
{
    int i;
    
    if (encryptedChar > 31 + key)
        i = encryptedChar - key;
    else
        i = encryptedChar + 95 - key;
    
    char decryptedChar=i;
    
    return decryptedChar;
}

string decryptString (string encryptStr, int key)
{
    string newStr(encryptStr);// new Str is the decrypted string.
    
    for (int i = 0; i < encryptStr.size(); i++)
        newStr[i] = decryptChar(encryptStr[i],key);
    
    return newStr;
}
