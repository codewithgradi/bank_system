#include <iostream>
using namespace std;

class Cipher
{

private:
    Cipher() {}

public:
    static string Encrypt(string content);

    static string Decrypt(string encryptedText);
};