


// github.com/cegme/cs3113fa22

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a hash lik counting thing

struct entry {
	int count; // 4 bytes
	//unsigned char *thing; // ??
	unsigned char thing[10]; // 10 bytes
};
typedef struct entry entry;

int printentry(entry e) {
	printf("<%s:%d>\n", e.thing, e.count);
	return 0;
}

int main(int argc, char **argv) {


	entry entries[300];

	// Create entries
	char a = 'a';
	for (size_t i = 0; i < 26; ++i, ++a) {
		// Create a an entry
		// put it in entries
		entries[i].count = i;
		memcpy(entries[i].thing, &a, 1);
		entries[i].thing[1] = '\0';
	}
	for (size_t i = 0; i < 26; ++i) {
		printentry(entries[i]);
	}

	// How do we find "s"?
	for (size_t i = 0; i < 26; ++i) {
		//if(entries[i].thing == "s") {
		if(strcmp(entries[i].thing, "s")==0) {
			printf("Found s!! index:%ld\n", i);
			printentry(entries[i]);
		}
	}

	return 0;
}



/*
 *
 * <s:1>
 * <t:5>
 * <u:3>
 *
 *
 * How do we store a list of entries?
 * How do we look for a specific entry?
 */ 


