/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

#include <iostream>
#include <string>

using namespace std;

static  string Decode(string data);
bool    has_dup_char(string s);

//  DRIVE

int     main(void)
{
        string sub, s;
        int         i;

        cin >> s;
        i = -1;
        while (s[++i])
        {
            sub = s.substr( i, 16 );
            if (!has_dup_char(sub) && sub.length() == 16)
            {
                cout << sub << endl;
                cout << Decode(sub) << endl;
            }
        }

        return (0);
}

bool    has_dup_char(string s)
{
        int     i, j;

        i = -1;
        while (++i < (int) s.length() - 1)
        {
            j = i;
            while (++j < (int) s.length())
            {
                if (s[i] == s[j])   return (true);
            }    
        }
        return (false);
}

//  base64 decoding

static char CharToSixBit(char c)
{
	char lookupTable[] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
		'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
		'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
	};

	if (c == '=')
	{
		return 0;
	}
	else
	{
		for (int x = 0; x < 64; x++)
		{
			if (lookupTable[x] == c)
				return (char)x;
		}

		return 0;
	}
}

static string Decode(string data)
{
	int length, length2, length3;
	int blockCount;
	int paddingCount = 0;
	int dataLength = data.length();

	length = dataLength;
	blockCount = length / 4;
	length2 = blockCount * 3;

	for (int x = 0; x < 2; x++)
	{
		if (data[length - x - 1] == '=')
			paddingCount++;
	}

	char* buffer = new char[length];
	char* buffer2 = new char[length2];

	for (int x = 0; x < length; x++)
	{
		buffer[x] = CharToSixBit(data[x]);
	}

	char b, b1, b2, b3;
	char temp1, temp2, temp3, temp4;

	for (int x = 0; x < blockCount; x++)
	{
		temp1 = buffer[x * 4];
		temp2 = buffer[x * 4 + 1];
		temp3 = buffer[x * 4 + 2];
		temp4 = buffer[x * 4 + 3];

		b = (char)(temp1 << 2);
		b1 = (char)((temp2 & 48) >> 4);
		b1 += b;

		b = (char)((temp2 & 15) << 4);
		b2 = (char)((temp3 & 60) >> 2);
		b2 += b;

		b = (char)((temp3 & 3) << 6);
		b3 = temp4;
		b3 += b;

		buffer2[x * 3] = b1;
		buffer2[x * 3 + 1] = b2;
		buffer2[x * 3 + 2] = b3;
	}

	length3 = length2 - paddingCount;
	string result;

	for (int x = 0; x < length3; x++)
	{
		result += buffer2[x];
	}

	delete[] buffer;
	delete[] buffer2;

	return result;
}
