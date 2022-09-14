

/* Hello i am typing a c comment */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned char T_GO   = (1<<0);    // Green light
const unsigned char T_SLOW = (1<<1);    // Yellow light
const unsigned char T_STOP = (1<<2);    // Red light
const unsigned char T_LGO  = (1<<3);    // Left turn green
const unsigned char T_LSLOW = (1<<4);    // Left turn yellow
const unsigned char T_LSTOP = (1<<5);    // Left turn red



int display(unsigned char sig) {
  printf("----------------\n");
  if(sig & T_GO) {
    printf("F: green\n");
  }
  if(sig & T_SLOW) {
    printf("F: yellow\n");
  }
  if(sig & T_STOP) {
    printf("F: red\n");
  }
  // NEW
  if(sig & T_LGO) {
    printf("L: green\n");
  }
  if(sig & T_LSLOW) {
    printf("L: yellow\n");
  }
  if(sig & T_LSTOP) {
    printf("L: red\n");
  }

}



int main(int argc, char** argv, char** envp) {

  unsigned char signal = T_GO | T_LGO;
  display(signal);

  // Green off; yellow on: doesn't change left turn
  signal = (signal & ~T_GO) | T_SLOW;
  display(signal);

  // NEW
  
  // Yellow off; red on: doesn't change left turn
  signal = (signal & ~T_SLOW) | T_STOP;
  display(signal);

  return 0;
}



