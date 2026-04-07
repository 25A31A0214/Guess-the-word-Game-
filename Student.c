
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[] = "COMPUTER";
    char guess[20];
    char ch;
    int i, length, attempts = 6;
    int correct = 0, found;

    length = strlen(word);

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

        for (i = 0; i < length; i++) {
            if (guess[i] == ch) {
                printf("You already guessed '%c'!\n", ch);
                found = 1;
                break;
            }

            if (word[i] == ch && guess[i] == '_') {
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
        printf("\n🎉 Congratulations! You guessed the word: %s\n", word);
    else
        printf("\n💀 Game Over! The word was: %s\n", word);

    return 0;
}
