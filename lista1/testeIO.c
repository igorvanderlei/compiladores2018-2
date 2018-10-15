#include <stdio.h>
#include <string.h>

int main(int argc , char* argv) {
		char buffer[256];
		while(fgets(buffer, 256, stdin) != NULL) {
			printf("%s", buffer);
		}

}
