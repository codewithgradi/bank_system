#include <iostream>
#include "Cipher.h"

using namespace std;

string Cipher::Encrypt(string content)
{

    string encriptedText = "";
    for (int i = 0; i < content.length(); i++)
    {
        char charater = content[i] + 5;
        encriptedText += to_string(charater);
    }
    return encriptedText;
};

string Cipher::Decrypt(string encryptedText)
{

    string decryptedText = "";
    for (int i = 0; i < encryptedText.length(); i++)
    {
        char character = encryptedText[i] - 5;
        decryptedText += character;
    }
    return decryptedText;
}