#include <iostream>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include <string.h>

using namespace std;

string fn_Encrypt(string value)
{

	char asciiBytes[1024];
	sprintf(asciiBytes,"%s",value.c_str());
	string strEncrypted;
	int iVal=0,arInt,baseValue=0;
	char cEncrypted[strlen(asciiBytes)];
	for(iVal=0;iVal<strlen(asciiBytes);iVal++)
	{

		char c = asciiBytes[iVal];
		arInt = static_cast<int>(c) + baseValue; //Convert.ToInt32(by) - iVal; // Add ASCII value + Position of the character
		if(baseValue==10)
			baseValue=0;
		else
			baseValue++;

		cEncrypted[iVal] = static_cast<int> (arInt);

	}
	cEncrypted[iVal]='\0';
	strEncrypted.assign(cEncrypted);
	return strEncrypted;

}
string fn_Decrypt(string value)
{

	//byte[] asciiBytes = Encoding.ASCII.GetBytes(value);
	char asciiBytes[1024];
	sprintf(asciiBytes,"%s",value.c_str());

	unsigned int iVal = 0;

	string strDecrypted;// = string.Empty;
	strDecrypted.clear();
	//int arInt[strlen(asciiBytes)]; //= new int[asciiBytes.Length];
	char cDecrypted[strlen(asciiBytes)];
	int arInt;

	//foreach (byte by in asciiBytes)
	int baseValue=0;
	for(iVal=0;iVal<strlen(asciiBytes);iVal++)
	{

		char c = asciiBytes[iVal];
		arInt = static_cast<int>(c) - baseValue; //Convert.ToInt32(by) - iVal; // Add ASCII value + Position of the character
		if(baseValue==10)
			baseValue=0;
		else
			baseValue++;

		cDecrypted[iVal] = static_cast<int> (arInt);

	}
	cDecrypted[iVal]='\0';
	strDecrypted.assign(cDecrypted);
	//printf("%s\n",strDecrypted.c_str());
	return strDecrypted;

}

int main(int argc, char* argv[]){
    string data;
    /*
    for(int i=0; i<argc; i++) {   
            data=fn_Encrypt(argv[i]);
    }*/
data=fn_Encrypt(argv[1]);
//data=fn_Encrypt("627294846328");
std::cout<<"\n**************ENCRYPTED**************\n" << data<<std::endl;

data=fn_Decrypt(argv[2]);
std::cout<<"\n\n**************DECRYPTED**************\n" <<data<<std::endl<<std::endl<<std::endl;

}