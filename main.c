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
	char toCheck[8] = {'!', '@', '#', '$', '^', '(', ')','%'};
	bool badCharExists, wrongLength, duplicateStringsExist;

	printf("Enter unique ten character strings with a length between 1 and 25 characters.  The following characters are not allowed: !, @, #, $, %%, ^, (, ).\n");

	for( int i = 0; i < 10; i++) {
		printf("Enter string %d: ", i + 1);

		//Perform string checks for length, characters, and duplicate strings
		wrongLength = true, badCharExists = true, duplicateStringsExist = true;
		while( wrongLength || badCharExists || duplicateStringsExist) {
			fgets(buffer, 26, stdin);
			//Checking length
			if(strlen(buffer) < 2 || strlen(buffer) > 25 || strchr(buffer, '\n') == NULL) {
				printf("Please enter a string between 1 and 25 characters: ");
				wrongLength = true;
				if(strchr(buffer, '\n') == NULL) {
					int c;
					while((c = fgetc(stdin)) != '\n' && c != EOF);
				}
			}
			else {
				wrongLength = false;
			}

			//Checking illegal characters
			int size = sizeof(toCheck)/sizeof(toCheck[0]);
			for(int j = 0; j < size; j++) {
				if(strchr(buffer, toCheck[j]) != NULL) {
					printf("The characters !, @, #, $, %%, ^, (, ) are not allowed.  Please reenter a string.");
					badCharExists = true;
					break;
				}
				else {
					badCharExists = false;
				}
			}

			//Checking duplicate Strings
			for (int k = 0; k < i; k++) {
				if(strcmp(storage[k], buffer) == 0){
					duplicateStringsExist = true;
					printf("Please enter an unique string.");
					break;
				}
				else {
					duplicateStringsExist = false;
				}
			}
			//First string input has nothing to compare to.
			if(i == 0) {
				duplicateStringsExist = false;
			}

			//If all conditions are fulfilled, break from the user input request loop
			if(!wrongLength && !badCharExists && !duplicateStringsExist) {
				break;
			}
		}
		
		//All conditions fulfilled, store the string 
		strcpy(storage[i], buffer);
		printf("Storage[%d]: %s, length: %lu\n", i, storage[i], strlen(storage[i]));
	}

	//2. Sort the strings based on ASCII value
	//3. Print the sorted strings by value in ascending or descending value, depending on user input
	//4. Print and label the string with the highest ASCII value and the lowest value.
	return 0;
}