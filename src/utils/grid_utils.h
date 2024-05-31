#ifndef GRID_UTILS_H
#define GRID_UTILS_H
#include "shared/typedefs.h"
#include <stdbool.h>

int choose_random_position(int grid_length);
bool validate_position(int *coords, int grid_length, SelectedWord word,
                       Direction direction, Table table);
bool is_cell_filled(Table table, int *coords);
Direction choose_random_direction();

int *change_position_to_coordinate(int number, int cols);
int change_coordinate_to_position(int *coords, int cols);
void place_word_in_table(SelectedWord word, Table table, TableData table_data);
void fill_grid_with_characters(Table table);

#endif // GRID_UTILS_H
