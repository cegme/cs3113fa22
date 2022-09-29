


// github.com/cegme/cs3113fa22

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * Read from a file and print the contents
 */

int main (int argc, char **argv) {

	const char * filename = "emoji.txt";
	int readval;
	int fd = open(filename, O_RDONLY);

	// check for errors
	
	// Read one byte at a time
	
	unsigned char buf;
	readval = read(fd, &buf, 1);
	printf("The byte: %c\n", buf);
	
	unsigned char emoji[5]; // Null terminator
	readval = read(fd, emoji, 4);
	// null terminator?>?
	emoji[4] = '\0';
	printf("The byte: %s->5\n", emoji);

	// What is the hex representation of the first 
	// byte of the emoji char
	if((emoji[0] & 0x80) == 0x80) {
		printf("This is an emoji!!\n");
	}
	if((buf & 0x80) == 0x80) {
		printf("This is an emoji!!\n");
	}
	printf("(emoji[0] & 0x80): %x\n", (emoji[0] & 0x80));
	printf("(buf & 0x80): %x\n", (buf & 0x80));



	if(0) {
		printf("Here 0\n");
	}
	if (1) {
		printf("Here 1\n");
	}

	close(fd);

	return 0;
}

/*
 * char * s = "sarah";
 * ['s', 'a', 'r', 'a', 'h', '\0']
 * ['0x73', '0x61', 'r', 'a', 'h', '\0']
 * ['0x0f', '0x04', '\0'] 
 */
