#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
int main() {
    char* fname = "testInput";
    FILE *fp;
    char* s;
    int f = 0;
    int t = 0;
    int w = 0;
    fp = fopen(fname, "r");
    if (fp == NULL) {
      perror("error\n");
      exit(-1);
    }
    s = readToken(fp);
    while (!feof(fp)) {
      f = atoi(s);
      t = atoi(readToken(fp));
      s = readToken(fp);
      if (strcmp(s, ";") == 0) {
        //s = readToken(fp);
        w = 1;
        //printf("%d, %d, %d\n", f, t, w);
        //continue;
      } else {
          w = atoi(s);
          readToken(fp);
          //if (!feof(fp)) {
            //  s = readToken(fp);
          //}
          //printf("%d, %d, %d\n", f, t, w);
          //continue;
      }
      
      printf("%d, %d, %d\n", f, t, w); // insert into graph

      if (!feof(fp)) {
          s = readToken(fp);
      }
    }
}
