#ifndef TYPEDEFS_H
#define TYPEDEFS_H

typedef enum Direction { HORIZONTAL, VERTICAL } Direction;

typedef struct {
  // int id;
  int *position;
  char *word;
  Direction direction;
} TableData;

typedef struct {
  int length;
  int total_words;
  int table_length;
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

#endif // DATA_H
