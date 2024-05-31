#ifndef TYPEDEFS_H
#define TYPEDEFS_H
#include <gtk/gtk.h>
typedef enum Direction { HORIZONTAL, VERTICAL } Direction;
typedef enum Difficulty { EASY, MEDIUM, HARD } Difficulty;
typedef struct {
  // int id;
  int *position;
  char *word;
  Direction direction;
} TableData;

typedef struct {
  int total_words;
  int table_length;
  Difficulty difficulty;
  char **words;
  char **table;
} Table;

typedef struct {
  char *word;
  int word_length;
} SelectedWord;

typedef struct {
  char *name;
  char *title;
} CreatePageParams;

typedef struct {
  Table *table;
  GtkWidget *stack;
} SelectDifficultyParams;
#endif // DATA_H
