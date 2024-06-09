#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "typedefs.h"
#include <gtk/gtk.h>

LoadWordsReturn *load_words(const char *filepath, const int total_words);
void save_scores(AppConfig *app_config);
#endif