#include "login_utils.h"
#include <stdio.h>

void save_login_data(char *username, char *password) {
  FILE *fp = fopen("../credentials.txt", "a+");
  if (fp == NULL) {
    fputs("Cannot open users.txt file.", stderr);
    return;
  }

  fprintf(fp, "%s %s\n", username, password);
  fclose(fp);
  return;
}