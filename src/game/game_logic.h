#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "../shared/typedefs.h"
#include <gtk/gtk.h>
#include <stdbool.h>

void initialize_game(int grid_length, char **words, Table table,
                     TableData *table_data);

// Check if the cell is already filled

// Returns Coordinate in array [int row, int col]

#endif // GAME_LOGIC_H
