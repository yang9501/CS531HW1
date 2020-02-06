#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Things to decide. 
//	1. Hashing would be faster than iteratively detecting duplicate strings.  
//	2. Do I want to take the time to implement something more sophisticated than bubble sort?


int main() {
	//1.  Retrieve Strings from user
	//	A. Check for length
	//	B. Check for duplicates
	//	C. Check for illegal characters
	char buffer[26];
	char storage[10][26];
	char toCheck[5] = {'!', '@', '#', '$', '%', '^', '(', ')'};
	bool badCharExists, wrongLength, duplicateStringsExist;

	printf("Enter unique ten character strings with a length between 1 and 25 characters.  The following characters are not allowed: !, @, #, $, %%, ^, (, ).\n");

	for( int i = 0; i < 10; i++) {
		printf("Enter string %d: ", i + 1);
		fgets(buffer, 26, stdin);

		//Perform string checks for length, characters, and duplicate strings
		wrongLength, badCharExists, duplicateStringsExist = true;
		while( wrongLength || badCharExists/* || OR ONE OF THE DISALLOWED CHARACTERS ARE WITHIN THE STRING OR IS A DUPLICATE STRING*/) {
			//Checking length
			if(strlen(buffer) < 2 || strlen(buffer) > 25) {
				printf("Please enter a string between 1 and 25 characters: ");
			}
			else {
				wrongLength = false;
			}

			//Checking illegal characters
			int size = sizeof(toCheck)/sizeof(toCheck[0]);
			for(int j = 0; j < size; j++) {
				printf("this line is reached\n");
				if(strchr(buffer, toCheck[j]) != NULL) {
					printf("The characters !, @, #, $, %%, ^, (, ) are not allowed.  Please reenter a string.\n");
					badCharExists = true;
					break;
				}
				else {
					badCharExists = false;
				}
			}

			if(wrongLength || badCharExists /*|| duplicateStringsExist*/) {
				fgets(buffer, 26, stdin);
			}
		}
		
		strcpy(storage[i], buffer);
		printf("Storage[%d]: %s, length: %lu\n", i, storage[i], strlen(storage[i]));
		

	}

	printf("Size of char buffer is : %lu\n", strlen(buffer));

	//2. Sort the strings based on ASCII value
	//3. Print the sorted strings by value in ascending or descending value, depending on user input
	//4. Print and label the string with the highest ASCII value and the lowest value.
	return 0;

}