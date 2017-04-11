/*
 * Count the frequency of each word in a plain text file.
 */


#include <stdio.h>
#include <glib.h>


int main() {

    // Create a new hash table
    GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);

    // Open text.txt
    FILE *fp = fopen("text.txt", "r");

    // Loop through each word in text.txt
    char word[100];
    int* old_count;
    int count;
    while (fscanf(fp, "%s", word) == 1) {
        printf("Next word: %s\n", word);
        // If the word is already in the hash, increment the count of that word
        if (g_hash_table_contains(hash, word) == 1) {
            printf("Word already exists.\n");
            old_count = g_hash_table_lookup(hash, word);
            count = *old_count + 1;
            g_hash_table_replace(hash, word, &count);
        }
        // If the word is not in the hash, add it to the hash with a count of 1
        else {
            printf("Word created.\n");
            count = 1;
            g_hash_table_insert(hash, word, &count);
        }

        // Print out the updated list of words and their frequencies
        printf("%s: %d\n\n", word, count);
    }
}
