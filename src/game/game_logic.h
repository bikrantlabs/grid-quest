#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "../shared/typedefs.h"
#include <gtk/gtk.h>
#include <stdbool.h>

void initialize_game(int grid_length, char **words, Table table,
                     TableData *table_data);

void fill_grid(char **grid, char **word, int rows, int cols);

/*
 * Select random word from array
 */
SelectedWord choose_random_word(char **word, int total_words);
Direction choose_random_direction();

// Choose random position
int choose_random_position(int grid_length);
bool validate_position(int *coords, int grid_length, SelectedWord word,
                       Direction direction, Table table);
// Check if the cell is already filled
bool is_cell_filled(Table table, int *coords);
int longest_word_in_array(char **word, int total_words);

// Returns Coordinate in array [int row, int col]
int *change_position_to_coordinate(int number, int cols);
int change_coordinate_to_position(int *coords, int cols);
void place_word_in_table(SelectedWord word, Table table, TableData table_data);
void fill_grid_with_characters(Table table);
// Generate random character from A to Z;
char generate_random_character();

#endif // GAME_LOGIC_H
