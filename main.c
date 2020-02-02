#include <stdio.h>
#include <string.h>

int main() {
	char buffer[10][26];
	
	for (int i = 0; i < 10; ++i) {
		fgets(buffer[i], 26, stdin);
	}
	

	printf("Size of char buffer is: %lu\n", strlen(buffer[0]));
	return 0;
}