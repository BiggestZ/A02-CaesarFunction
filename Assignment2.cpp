//
// Name : Zahir Choudhry
// SSID : 1830915
// Assignment #: 2
// Submission Date : 10/3/2020
//
// Description : A program to encrypt and decrypt a message using a shift cipher
// The plaintext message must only contain lowercase alpha and digits 0 -9
//
// command line arguments
// -p theplaintextmessage1 - the plaintext (p) message to be encrypted
// -C 2 qnyujrw2n62vn11jpna - the cipher (C) text to be decrypted
// -k 9 - the key (k) shift value
// -E - the option to encrypt (E)
// -D - the option to decrypt (D)
//
#include <iostream> // std :: cout , std :: cin , etc.
#include <cstdlib> //C++ version of stdlib .h
#include <cstring> //C++ version of string .h
#include <string>
using namespace std;

    int k = 0; // k shift
    int msg_index = 0; // msg_index of plaintext or ciphertext in argv
    string msg ; // string to hold the plaintext or ciphertext ;
    bool do_encrypt = false ; // True for encrypt or False for decrypt
    string result;  // what will be ct/pt

char codebook [] =
{
'a','A','b','B','c','C','d','D','e','E','f','F','g','G','h','H','i','I' ,\
'j','J','k','K','l','L','m','M','n','N','o','O','p','P','q','Q','r','R' ,\
's','S','t','T','u','U','v','V','w','W','x','X','y','Y','z','Z','0','1' ,\
'2','3','4','5','6','7','8','9','@','$'
};

int cBL = sizeof(codebook)/sizeof(codebook[0]);

// Todo A2: encrypt using std :: string
void encrypt (std::string& plaintext,int k);

// Todo A2: decrypt using std :: string
void decrypt (std::string& ciphertext,int k);

// Todo A2: helper function to copy a cstring to an std :: string
void copy_string (std::string& s ,char* text);

int main (int argc, char * argv [])
{
//Example variables for A02
    
    if(argc != 6){ //Will stop code if input is too small
        cout << "Too short";
        return 0;
    }
    
    for (int i = 1; i < argc ; i++){
        if (strcmp(argv[i],"-k")==0 || strcmp(argv[i],"-K")==0){
            k = atoi(argv[++i]); //find how to set K to val after -k
            // ANSWER: atoi function
        }
        if(strcmp(argv[i],"-p")==0 || strcmp(argv[i],"-P")==0){
            msg_index = i+1;
            //msg = argv[i+1];   Could be used as alternative to copy function         
        }
        if(strcmp(argv[i],"-c")==0 || strcmp(argv[i],"-C")==0){
            msg_index = i+1;            
            //msg = argv[i+1];    Could be used as alternative to copy function
        }
        
        if(strcmp(argv[i],"-e")==0 || strcmp(argv[i],"-E")==0 ){
            do_encrypt = true;         // Checks encrypt
        }
    }
        
//
// A1: process the command line arguments
//
// Todo A2: copy argv into msg using copy_string function
//
copy_string(msg,argv[msg_index]);

// Todo A2: call encrypt or decrypt functions
//
if (do_encrypt) // encrypt plaintext
encrypt (msg,k);
else 
decrypt (msg,k); // decrypt ciphertext
//
// Todo A2:
// print the original message and the plaintext | ciphertext
//
return 0;
}
 //main

void encrypt(std::string& plaintext, int k){
    for(int i = 0; i < plaintext.length();i++){ // iterates Length of plaintext
        for(int p = 0; p < cBL; p++){ // iterates Length of CodeBook
            if(plaintext.at(i) == codebook[p])
                result += codebook[(p+k)%64];
        }
    }
    cout << "The Encrypted message is " << msg << endl;
    cout << "The Decrypted message is " << result << endl;
};

void decrypt(std::string& ciphertext, int k){
    for(int i = 0; i < ciphertext.length();i++){ //iterates through ciphertxt
        for(int p = 0; p < cBL; p++){ //interates through codebook for each char of ciphertxt
            if(ciphertext.at(i) == codebook[p]) //if the characters are the same...
                result += codebook[((p-k)+64)%64];       
        }
    }
    cout << "The Decrypted message is " << msg << endl;
    cout << "The Encrypted message is " << result << endl;
};

void copy_string(std::string& s, char* text){
    for(int i = 0; text[i] != '\0';i++){
        s+= text[i]; 
    }
};
