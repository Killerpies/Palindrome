#include <iostream>
#include<stdio.h>
#include<string.h>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

/**
 * Function Reverses the characters of a string by reference. ie.. 123 becomes 321
 * Param - & string
 */
void reverseStr(string &str) {
	int n = str.length();

	// Swap character starting from two
	// corners
	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}


/**
 *
 * Takes a single string number and int representing length
 * Determins if palindrone, if not then adds them continually until the number is a palindrone
 *
 * Param Number - String number that we will test if palindrone
 * Param Length - Integer representing the length of the string
 * Return tempStringResult - String containing answer for specific number
 */
string solver(string number, int length) {
	//initial variable declarations
	string tempResultString = "";
	string startNumber;
	string reversedNumber;
	int count = 0;


	//Checking to make sure this is not just an empty string
	if (number != "\0") {
		//If string is not empty, set values appropriately
		count += 1;
		startNumber = number;
		reversedNumber = startNumber;
		reverseStr(reversedNumber);

		//Convert string to long long type in order to add together
		long long longStartNumber = stoll(startNumber);
		long long longReversedNumber = stoll(reversedNumber);

		//Add the values together
		long long x = abs(longStartNumber) + abs(longReversedNumber);

		//Convert new value back to string
		startNumber = to_string(x);
		reversedNumber = startNumber;

		// reverse that value again
		reverseStr(reversedNumber);


		//If the new value and reverse value are not the same then repeat
		while (startNumber != reversedNumber) {
			count += 1;

			// int's cannot contain variables bigger than 10 digits need long long
			long long myint1 = stoll(startNumber);
			long long myint2 = stoll(reversedNumber);
			long long x = abs(myint1) + abs(myint2);

			startNumber = to_string(x);
			reversedNumber = startNumber;
			reverseStr(reversedNumber);

		}
	}

	//If the value is just an empty string then return an empty string
	if (count == 0) {
		return tempResultString;
	}

	//Take the count, convert to string
	string strIndex = to_string(count);

	//Add count and reversed number to a string together and return
	tempResultString = strIndex + " " + reversedNumber;
	return tempResultString;
}

/**
 *Takes a string of numbers to test
 *Determines how many cycles of adding it will take for the number to be a palindrone
 *Param *numbers - cstring of numbers to test
 *Returns C-string containing answer
 */
char* process(const char *numbers) {
	//Initial variables declared
	int strLength;
	strLength = strlen(numbers);
	string strResult = "";
	string tempValueStr = "";


	// Loop through cstring and separate by spaces
	for (int i = 0; i <= strLength; i++) {
		//Determine if the character is an empty spaces or is at the end of the string
		if (numbers[i] == ' ' || i == strLength) {
			// at the end of the string
			if (i == strLength) {
				//Add returned value to result
				strResult += solver(tempValueStr, i);
				//Reset tempvalue
				tempValueStr = "";
				// if not at the end of the string
			} else {
				// add returned value to result
				strResult += solver(tempValueStr, i) + " ";
				//reset temp value
				tempValueStr = "";
			}
		} else {
			//continue adding the numbers to tempValueStr if there is no space or end of string
			tempValueStr += numbers[i];
		}
	}

	//convert results back to cstring and return
	char* cResult = strcpy(new char[strResult.length() + 1], strResult.c_str());
	return cResult;
}
