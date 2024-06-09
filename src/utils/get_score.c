#include "file_utils.h"
#include "login_utils.h"
#include <stdio.h>
bool check_score_exists(char *username) {
  FILE *fp = fopen("../scores.txt", "r");
  if (fp == NULL) {
    fputs("Cannot open credentials.txt file.", stderr);
    return false;
  }

  char saved_username[100]; // Assuming each line in the file is no longer than
                            // 100
  int score;
  // characters
  while (fscanf(fp, "%s %d\n", saved_username, &score) != EOF) {
    if (strcmp(saved_username, username) == 0) {
      fclose(fp);
      return true;
    }
  }
  fclose(fp);
  return false;
}
int get_score(char *username) {
  FILE *fp = fopen("../scores.txt", "r");
  if (fp == NULL) {
    fputs("Cannot open scores.txt file.", stderr);
    return false;
  }
  char _username[MAX_USERNAME_LENGTH];
  int score;
  if (check_score_exists(username)) {
    while (fscanf(fp, "%s %d\n", _username, &score) != EOF) {
      if (strcmp(_username, username) == 0) {
        fclose(fp);
        return score;
      }
    }
  }
  fclose(fp);
  return 0;
}
