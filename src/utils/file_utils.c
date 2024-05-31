// #include "file_utils.h"
// #include "typedefs.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// LoadWordsReturn *load_words(const char *filepath) {
//   FILE *in;
//   char word[30];
//   int words = 0;

//   // Open the file
//   in = fopen(filepath, "r");
//   if (in == NULL) {
//     fputs("Cannot open dictionary file.", stderr);
//     return NULL;
//   }

//   // First pass: count the number of words
//   while (fscanf(in, "%29s", word) == 1) {
//     words++;
//   }

//   // Allocate memory for the LoadWordsReturn structure
//   LoadWordsReturn *word_data = malloc(sizeof(LoadWordsReturn));
//   if (word_data == NULL) {
//     fputs("Memory allocation failed for LoadWordsReturn.", stderr);
//     fclose(in);
//     return NULL;
//   }

//   word_data->total_words = words;

//   if (words == 0) {
//     fputs("No words found in the file.", stderr);
//     fclose(in);
//     free(word_data);
//     return NULL;
//   }

//   // Allocate memory for the words array
//   word_data->words = malloc(words * sizeof(char *));
//   if (word_data->words == NULL) {
//     fputs("Memory allocation failed for words array.", stderr);
//     fclose(in);
//     free(word_data);
//     return NULL;
//   }

//   // Second pass: read the words
//   rewind(in);
//   int index = 0;
//   while (fscanf(in, "%29s", word) == 1) {
//     word_data->words[index] = strdup(word);
//     if (word_data->words[index] == NULL) {
//       fputs("Memory allocation failed for word string.", stderr);
//       // Free previously allocated memory before returning
//       for (int i = 0; i < index; i++) {
//         free(word_data->words[i]);
//       }
//       free(word_data->words);
//       free(word_data);
//       fclose(in);
//       return NULL;
//     }
//     index++;
//   }

//   // Close the file
//   fclose(in);
//   return word_data;
// }
