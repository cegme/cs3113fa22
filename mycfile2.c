

/* Hello i am typing a c comment */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979
#define HALFOF(x) x/2
#define TRUE 1
#define FALSE 0

#define MAX_NAME 60

struct roster {
  short number;
  char team[MAX_NAME];
};

typedef struct roster ros;

int rostercomp(const void *left, const void *right) {
  const ros *a = (const ros*) left;
  const ros *b = (const ros*) right;

  //(*a).number;
  return (a->number - b->number);
  
}




int printroster(ros r) {
  printf("<%d: %s>\n", r.number, r.team);
  //r.number = 2;
  //printf("\t<%d: %s>\n", r.number, r.team);
  return 0;
}


int main(int argc, char** argv, char** envp) {

  printf("Hello, World!\n");

  /*
  // What is argc?
  printf("argc: %d\n", argc); 

  // Argv?? lets see it
  for(int i = 0; i < argc; ++i) {
    printf("\targv[%d]: %s\n", i, argv[i]);
  }
  */
  
  char c;
  long mylong;
  int myint;
  float myfloat;
  double mydouble;

  printf("s(char): %ld\n", sizeof(c));
  printf("s(int): %ld\n", sizeof(myint));
  printf("s(long): %ld\n", sizeof(mylong));
  printf("s(float): %ld\n", sizeof(myfloat));
  printf("s(double): %ld\n", sizeof(mydouble));

  //  ++i vs i++
  int i;
  i = 0;
  printf("i post: %d\n", ++i);
  i = 0;
  printf("i pre: %d\n", i++);
  
  // Pointers
  int box;
  int box2;
  box = 0xA;
  
  printf("box: %d\n", box);
  printf("size box: %ld\n", sizeof(box));
  printf("pointer to box: %p\n", &box);
  printf("pointer to box: %p\n", &box2);

  int *label;
  label = &box;
  
  printf("size *int: %ld\n", sizeof(label));

  *label = 0x10;
  printf("%d %d\n", box, *label);

  int **qrcode = &label;
  printf("%d %d %d\n", box, *label, **qrcode);

  // Arrays
  /*
  char grades[4];
  grades[0] = 'a';
  grades[1] = 'b';
  grades[2] = 'c';
  grades[3] = 'd';
  */
  char grades[] = {'a', 'b', 'c', 'd'};

  printf("grades: %p, %c %c\n", grades, grades[0], *grades);
  
  for(i = 0; i < 4; ++i) {
    printf("%d: %c\n", i, grades[i]);
  }
  
  // structures
  
  ros r;
  r.number = 24;
  // r.name = "Sooner";
  strncpy(r.team, "Sooners", MAX_NAME);
  
  printroster(r);

  ros *org;
  org = &r;


  //printroster(*org);
  
  // dynamic allocation
  org = calloc(32, sizeof(ros));
  //org = malloc(32 * sizeof(ros));

  org[0].number = 13;
  strncpy(org[0].team, "Dolphins", MAX_NAME);

  org[1].number = 3;
  strncpy(org[1].team, "Heat", MAX_NAME);

  org[2].number = 0;
  strncpy(org[2].team, "Marlins", MAX_NAME);

  org[3].number = 9;
  strncpy(org[3].team, "Sooners", MAX_NAME);

  printf("-----------\n");
  for(int i = 0; i < 4; ++i) {
    printroster(org[i]);
  }

  /*
  printf("size = %ld\n", sizeof(ros));
  printf("org 0 : %p\n", org);
  printf("org 0 number: %p\n", &(org[0].number));
  printf("org 0 team: %p\n", &(org[0].team));
  printf("org 1 number: %p\n", &(org[1].number));
  printf("org 1 team: %p\n", &(org[1].team));
  */

  qsort(org, 4, sizeof(ros), rostercomp);
  
  printf("-----------\n");
  for(int i = 0; i < 4; ++i) {
    printroster(org[i]);
  }

	
  free(org);

  return 0;
}



