#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[] = "COMPUTER";
    char guess[20];
    char ch;
    int i, length, attempts = 6;
    int correct = 0;
    int found, already_guessed;

    length = strlen(word);

    // Initialize guess with '_'
    for (i = 0; i < length; i++) {
        guess[i] = '_';
    }
    guess[length] = '\0';

    printf("---- GUESS THE WORD GAME ----\n");

    while (attempts > 0 && correct < length) {
        printf("\nWord: %s", guess);
        printf("\nAttempts left: %d", attempts);
        printf("\nEnter a letter: ");
        scanf(" %c", &ch);

        ch = toupper(ch);

        if (!isalpha(ch)) {
            printf("Invalid input! Enter a letter.\n");
            continue;
        }

        found = 0;
        already_guessed = 0;

        // Check if already guessed
        for (i = 0; i < length; i++) {
            if (guess[i] == ch) {
                already_guessed = 1;
                break;
            }
        }

        if (already_guessed) {
            printf("You already guessed '%c'!\n", ch);
            continue;
        }

        // Check if character exists in word
        for (i = 0; i < length; i++) {
            if (word[i] == ch) {
                guess[i] = ch;
                correct++;
                found = 1;
            }
        }

        if (found)
            printf("Correct guess!\n");
        else {
            printf("Wrong guess!\n");
            attempts--;
        }
    }

    if (correct == length)
        printf("\nCongratulations! You guessed the word: %s\n", word);
    else
        printf("\nGame Over! The word was: %s\n", word);

    return 0;
}
