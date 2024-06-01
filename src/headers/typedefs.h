#ifndef TYPEDEFS_H
#define TYPEDEFS_H
#include <gtk/gtk.h>
typedef enum Direction { HORIZONTAL, VERTICAL } Direction;
typedef enum Difficulty { EASY, MEDIUM, HARD } Difficulty;

// Struct for savin game state like total words placed, their positions, etc
typedef struct {
  int *coords;
  char *word;
  int word_length;
  Direction direction;
} GameState;
// The config struct needed to initialize the game
typedef struct {
  int total_words;
  int table_length;
  char *filepath;
  char **words;
  char **table;
  int attempts;
  Difficulty difficulty;
  GameState *game_state;
} GameConfig;

typedef struct {
  char *word;
  int word_length;
} SelectedWord;

typedef struct {
  char *name;
  char *title;
} CreatePageParams;

typedef struct {
  char **words;
  int total_words;
} RandomSelectedWords;

typedef struct {
  int clicked_count;
  int *positions;
  int max_size;
} ClickedPositions;

typedef struct {
  GtkWidget *attempts_label;
  GtkWidget *stack;
  GtkWidget *button_grid;
  GtkWidget *word_hints_grid;
  GtkWidget *game_page;
  GtkWidget ***buttons;
  GtkWidget **word_hint_labels;
} UiConfig;

typedef struct {
  int new_position;
  ClickedPositions *clicked_positions;
  GameConfig *config;
  UiConfig *uiconfig;
  GtkWidget *button;
  GtkWidget *stack;
} ButtonClickData;

// typedef struct {
//   GameConfig *config;
//   UiConfig *uiconfig;
//   GtkWidget *stack;
//   GtkWidget *button_grid;
//   GtkWidget *word_hints_grid;
// } SelectDifficultyParams;

typedef struct {
  GameConfig *game_config;
  UiConfig *uiconfig;
} AppConfig;
#endif // DATA_H
