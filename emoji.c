


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

	close(fd);

	return 0;
}
