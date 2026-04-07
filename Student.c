#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#define MAX_WORDS 30
int main() {
    
    char *words[MAX_WORDS] = {
        "APPLE", "BRAVE", "CLOUD", "DREAM", "EARTH",
        "FLAME", "GRACE", "HOUSE", "IMAGE", "JUICE",
        "KNIFE", "LIGHT", "MIGHT", "NIGHT", "OCEAN",
        "PLANT", "QUEEN", "RIVER", "STONE", "TRAIN",
        "UNITY", "VOICE", "WATER", "YOUTH", "ZEBRA",
        "SMILE", "PRIDE", "SHINE", "SWEET", "GREEN"
    };

    int used[MAX_WORDS] = {0};
    int used_count = 0;

    srand(time(0));

    while (used_count < MAX_WORDS) {

        int index;

        
        do {
            index = rand() % MAX_WORDS;
        } while (used[index] == 1);

        used[index] = 1;
        used_count++;

        char word[10];
        strcpy(word, words[index]);

        int length = strlen(word);

        char guess[10];
        char ch;
        int attempts = 10;
        int correct = 0;


        for (int i = 0; i < length; i++)
            guess[i] = '_';
        guess[length] = '\0';

        printf("\n---- NEW WORD ----\n");
        printf("This is a %d-letter word.\n", length);

        while (attempts > 0 && correct < length) {
            printf("\nWord: %s", guess);
            printf("\nAttempts left: %d", attempts);
            printf("\nEnter a letter: ");
            scanf(" %c", &ch);

            ch = toupper(ch);

            if (!isalpha(ch)) {
                printf("Invalid input!\n");
                continue;
            }

            int found = 0, already = 0;

    
            for (int i = 0; i < length; i++) {
                if (guess[i] == ch) {
                    already = 1;
                    break;
                }
            }

            if (already) {
                printf("Already guessed '%c'\n", ch);
                continue;
            }
            for (int i = 0; i < length; i++) {
                if (word[i] == ch) {
                    guess[i] = ch;
                    correct++;
                    found = 1;
                }
            }

            if (found)
                printf("Correct!\n");
            else {
                printf("Wrong!\n");
                attempts--;
            }
        }

        if (correct == length)
            printf("\n🎉 You guessed: %s\n", word);
        else
            printf("\n💀 Game Over! The word was: %s\n", word);

        if (used_count == MAX_WORDS) {
            printf("\nNo more words left!\n");
            break;
        }

        char choice;
        printf("\nPlay next word? (y/n): ");
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y')
            break;
    }

    return 0;
}
