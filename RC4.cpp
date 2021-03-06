#include<iostream>
#include<string>
using namespace std;

char* init_K(char * key)
{
	char* K = new char[256];
	int len = strlen(key);
	for (int i = 0; i < 256; i++)
	{
		K[i] = key[(i%len)];
	}
	return K;
}

unsigned char* init_S(char * key)
{
	unsigned char* S = new unsigned  char[256];
	for (int i = 0; i < 256; i++)
	{
		S[i] = i;
	}
	char* K = init_K(key);
	int i, j = 0;
	for (i = 0; i < 256; i++)
	{
		j = (j + S[i] + K[i])%256;
		char temp = S[j];
		S[j] = S[i];
		S[i] = temp;
	}
	return S;
}


void RC4_encrypt(unsigned char * S,char * data)
{
	int len = strlen(data);
	int i=0,j=0,t = 0;
	char temp;
	for (; i < len; i++)
	{
		i = (i + 1) % 256;
		j = (j + S[i]) % 256;
		temp = S[j];
		S[j] = S[i];
		S[i] = temp;
		t = (S[i] + S[j]) % 256;
		data[i] ^= S[t];
	}
}

int main()
{

	char data[] = "Southeast University";
	char key[] = "abcde";
	unsigned char* S = init_S(key);
	unsigned char* S2=new unsigned char[256];
	for (int i = 0; i < 256; i++)
	{
		S2[i] = S[i];
	}
	cout << "加密前的明文：";
	for (int i = 0; i < 21; i++)
	{
		cout << std::hex << int(data[i]);
	}
	cout << endl;
	RC4_encrypt(S, data);
	cout << "密文：";
	for (int i = 0; i < 21; i++)
	{
		cout <<std::hex<<int(data[i]);
	}
	RC4_encrypt(S2, data);
	cout << endl;
	cout << "解密后的明文：";
	for (int i = 0; i < 21; i++)
	{
		cout <<std::hex<<int(data[i]);
	}
	
	return 0;
}
