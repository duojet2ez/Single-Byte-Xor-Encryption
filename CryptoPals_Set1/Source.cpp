#include<iostream>
#include<unordered_map>
#include<bitset>
using namespace std;

string ConvertHexBinary(string input)
{
	unordered_map<char, string> Map;
	Map['0'] = "0000";
	Map['1'] = "0001";
	Map['2'] = "0010";
	Map['3'] = "0011";
	Map['4'] = "0100";
	Map['5'] = "0101";
	Map['6'] = "0110";
	Map['7'] = "0111";
	Map['8'] = "1000";
	Map['9'] = "1001";
	Map['a'] = "1010";
	Map['A'] = "1010";
	Map['b'] = "1011";
	Map['B'] = "1011";
	Map['c'] = "1100";
	Map['C'] = "1100";
	Map['d'] = "1101";
	Map['D'] = "1101";
	Map['e'] = "1110";
	Map['E'] = "1110";
	Map['f'] = "1111";
	Map['F'] = "1111";
	int length = input.length();
	string binaryConversion = "";
	for (int i = 0; i < length; i++)
	{
		binaryConversion += Map[input[i]];
	}
	return binaryConversion;
}

string BinaryToHex(string input)
{
	unordered_map<string, string> Map;
	Map["0000"] = "0";
	Map["0001"] = "1";
	Map["0010"] = "2";
	Map["0011"] = "3";
	Map["0100"] = "4";
	Map["0101"] = "5";
	Map["0110"] = "6";
	Map["0111"] = "7";
	Map["1000"] = "8";
	Map["1001"] = "9";
	Map["1010"] = "A";
	Map["1010"] = "a";
	Map["1011"] = "B";
	Map["1011"] = "b";
	Map["1100"] = "C";
	Map["1100"] = "c";
	Map["1101"] = "D";
	Map["1101"] = "d";
	Map["1110"] = "E";
	Map["1110"] = "e";
	Map["1111"] = "F";
	Map["1111"] = "f";
	int length = input.length();
	string binaryConversion = "";
	int j = 0;
	while (j < length)
	{
		string buffer = "";
		for (int i = 0; i < 4; i++)
		{
			buffer += input[j];
			j++;
		}
		binaryConversion += Map[buffer];
	}
	return binaryConversion;
}

string ConvertHexToBase64(string input)
{
	string binary = ConvertHexBinary(input);
	int n = binary.length();
	unordered_map<string, string> Map;
	Map["000000"] = "A";
	Map["000001"] = "B";
	Map["000010"] = "C";
	Map["000011"] = "D";
	Map["000100"] = "E";
	Map["000101"] = "F";
	Map["000110"] = "G";
	Map["000111"] = "H";
	Map["001000"] = "I";
	Map["001001"] = "J";
	Map["001010"] = "K";
	Map["001011"] = "L";
	Map["001100"] = "M";
	Map["001101"] = "N";
	Map["001110"] = "O";
	Map["001111"] = "P";
	Map["010000"] = "Q";
	Map["010001"] = "R";
	Map["010010"] = "S";
	Map["010011"] = "T";
	Map["010100"] = "U";
	Map["010101"] = "V";
	Map["010110"] = "W";
	Map["010111"] = "X";
	Map["011000"] = "Y";
	Map["011001"] = "Z";
	Map["011010"] = "a";
	Map["011011"] = "b";
	Map["011100"] = "c";
	Map["011101"] = "d";
	Map["011110"] = "e";
	Map["011111"] = "f";
	Map["100000"] = "g";
	Map["100001"] = "h";
	Map["100010"] = "i";
	Map["100011"] = "j";
	Map["100100"] = "k";
	Map["100101"] = "l";
	Map["100110"] = "m";
	Map["100111"] = "n";
	Map["101000"] = "o";
	Map["101001"] = "p";
	Map["101010"] = "q";
	Map["101011"] = "r";
	Map["101100"] = "s";
	Map["101101"] = "t";
	Map["101110"] = "u";
	Map["101111"] = "v";
	Map["110000"] = "w";
	Map["110001"] = "x";
	Map["110010"] = "y";
	Map["110011"] = "z";
	Map["110100"] = "0";
	Map["110101"] = "1";
	Map["110110"] = "2";
	Map["110111"] = "3";
	Map["111000"] = "4";
	Map["111001"] = "5";
	Map["111010"] = "6";
	Map["111011"] = "7";
	Map["111100"] = "8";
	Map["111101"] = "9";
	Map["111110"] = "+";
	Map["111111"] = "/";

	string convertedBase64 = "";
	int i = 0;
	int c;
	while (i < n)
	{
		string buffer = "";
		c = 0;
		while (c < 6 && i < n)
		{
			buffer += binary[i];
			i++;
			c++;
		}
		if (buffer.length() == 2)
		{
			buffer += "0000";
			convertedBase64 += Map[buffer];
			convertedBase64 += "==";
		}
		else if (buffer.length() == 4)
		{
			buffer += "00";
			convertedBase64 += Map[buffer];
			convertedBase64 += "=";
		}
		else
			convertedBase64 += Map[buffer];
	}
	return convertedBase64;
}

//takes 2 equal length buffers of hex, translates to binary, and produces the xor combination 
string XORHex(string input1, string input2)
{
	if (input1.length() != input2.length())
	{
		cout << "Not equal length" << endl;
		return "SHIT";
	}
	string I1 = ConvertHexBinary(input1);
	string I2 = ConvertHexBinary(input2);
	string xorConvert = "";

	for (int i = 0; i < input1.length() * 4; i++)
	{
		if (I1[i] == '1' && I2[i] == '1')
		{
			xorConvert += '0';
		}
		else if (I1[i] == '0' && I2[i] == '0')
		{
			xorConvert += '0';
		}
		else
			xorConvert += '1';
	}
	return BinaryToHex(xorConvert);
}


string StringToBinary(string input)
{
	int n = input.length();
	string toOutput = "";
	for (int i = 0; i < n; i++)
	{
		toOutput += bitset<8>(input[i]).to_string();
	}
	return toOutput;
}

string CharToBinary(char input)
{
	return bitset<8>(input).to_string(); 
}

//encrypts a message using single byte xor method. Input is a string with key used. Outputs the encrypted binary string
string SingleKeyEncrypt(string input, char key)
{
	string keyToBinary = CharToBinary(key); 
	string binaryMessage = StringToBinary(input); 
	string encryptedMessageToBinary = ""; 
	int n = binaryMessage.length();

	for (int i = 0; i < n; i = i + 8)
	{
		string temp = "";
		int d = i + 8; 
		for (int j = i; j < d; j++)
		{
			temp += binaryMessage[j]; 
		}
		//iterate over key and temp comparing chars 
		for (int t = 0; t < 8; t++)
		{
			if (temp[t] == keyToBinary[t])
			{
				encryptedMessageToBinary += '0';
			}
			else encryptedMessageToBinary += '1'; 
		}
	}
	return encryptedMessageToBinary; 
}

//takes a binary value as string and returns matching ascii characters
string BinaryStringToString(string str)         
{
	string returnDecrypted = "";
	int n = str.length();
	for (int i = 0; i < n; i = i + 8)
	{
		char parsed = 0;
		int d = i + 8;
		int c = 0;
		for (int j = i; j < d; j++)
		{
			if (str[j] == '1')
			{
				parsed |= 1 << (7 - c);
			}
			c++;
		}
		returnDecrypted += parsed;
	}
	return returnDecrypted;
}   

//decrypts a single byte xor encrypted message by taking in an encrypted binary string and the key used to encrypt
string SingleKeyDecrypt(string input, char key)
{
	string keyToBinary = CharToBinary(key);
	string decryptedMessageInBinary = ""; 
	int n = input.length();
	for (int i = 0; i < n; i = i + 8)
	{
		string temp = "";
		int d = i + 8;
		for (int j = i; j < d; j++)
		{
			temp += input[j]; 
		}
		for (int p = 0; p < 8; p++)
		{
			if (temp[p] == keyToBinary[p])
			{
				decryptedMessageInBinary += '0';
			}
			else decryptedMessageInBinary += '1'; 
		}
	}
	return BinaryStringToString(decryptedMessageInBinary); 
}


int main()
{
	string encryptedBinary = SingleKeyEncrypt("Hello this is a secret message!", 'b');

	return 0; 
}