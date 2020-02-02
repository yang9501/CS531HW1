#include <stdio.h>
#include <string.h>

int main() {

	char buffer[26];
	char storage[10][26];

	for( int i = 0; i < 10; i++) {
		printf("Enter string %d", i + 1);
		fgets(buffer, 26, stdin);

		if(strlen(buffer) <= 25 && strlen(buffer) > 0) {
			strcpy(storage[i], buffer);
			printf("Storage[%d]: %s, length: %lu\n", i, storage[i], strlen(storage[i]));
		}

	}

	printf("Size of char buffer is : %lu\n", strlen(buffer));
	return 0;

}