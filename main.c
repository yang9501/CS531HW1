#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//Things to decide. 
//	1. Hashing would be faster than iteratively detecting duplicate strings.  
//	2. Do I want to take the time to implement something more sophisticated than bubble sort?

int compareString(void const * a, void const * b) {
	char const * aa = (char const *) a;
	char const * bb = (char const *) b;
	return strcmp(aa, bb);
}

int main() {
	//1.  Retrieve Strings from user
	//	A. Check for length
	//	B. Check for duplicates
	//	C. Check for illegal characters
	char buffer[26];
	char orderBuffer[2];
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
				//Have to 'use' the rest of stdin so that it doesn't overflow to next fgets
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
	printf("Pre-sorted strings are: \n");
	for( int x = 0; x < 10; x++) {
		printf("%d: %s\n", x + 1, storage[x]);
	}

	qsort(storage, 10, 26*sizeof(char), compareString);

	printf("Sorted strings are: \n");
	for( int x = 0; x < 10; x++) {
		printf("%d: %s\n", x + 1, storage[x]);
	}
	//3. Print the sorted strings by value in ascending or descending value, depending on user input
	bool improperInput = true;
	while (improperInput) {		
		printf("Choose a output order, (A)scending or (D)escending.  Please enter (A) or (D): \n");
		fgets(orderBuffer, sizeof(orderBuffer), stdin);
		printf("Input length: %lu\n", strlen(orderBuffer));
		if(strlen(orderBuffer) != 1 || strchr(buffer, '\n') == NULL) {
			printf("Enter (A) or (D) for (A)scending or (D)escending.\n");
			if(strchr(orderBuffer, '\n') == NULL) {
				int c;
				while((c = fgetc(stdin)) != '\n' && c != EOF);
			}
			improperInput = true;
			continue;
		}
		if(strcmp(orderBuffer, "A") == 0) {
			for(int i = 0; i < 10; i++) {
				printf("%s\n", storage[i]);
			}
			improperInput = false;
		}
		else if (strcmp(orderBuffer, "D") == 0) {
			for(int i = 9; i >= 0; i--) {
				printf("%s\n", storage[i]);
			}
			improperInput = false;
		}		
	}

	//4. Print and label the string with the highest ASCII value and the lowest value.
	return 0;
}