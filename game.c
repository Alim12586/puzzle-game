#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6
#define WORD "COPILOT"

int main() {
    char guess;
    int tries = 0;
    int correct = 0;
    int wordLength = strlen(WORD);
    char display[wordLength + 1];

    // Başlangıçta tüm harfler '_' ile gizlenir
    for (int i = 0; i < wordLength; i++) {
        display[i] = '_';
    }
    display[wordLength] = '\0';

    printf("Kelimeyi tahmin et! (%d yanlış hakkın var)\n", MAX_TRIES);
    printf("%s\n", display);

    while (tries < MAX_TRIES && correct < wordLength) {
        printf("Bir harf gir: ");
        scanf(" %c", &guess);
        guess = toupper(guess);

        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (WORD[i] == guess && display[i] == '_') {
                display[i] = guess;
                correct++;
                found = 1;
            }
        }

        if (!found) {
            tries++;
            printf("Yanlış! Kalan hakkın: %d\n", MAX_TRIES - tries);
        } else {
            printf("Doğru!\n");
        }

        printf("%s\n", display);
    }

    if (correct == wordLength) {
        printf("Tebrikler! Kelimeyi buldun: %s\n", WORD);
    } else {
        printf("Oyun bitti! Doğru kelime: %s\n", WORD);
    }

    return 0;
}