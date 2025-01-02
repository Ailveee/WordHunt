#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SCORE_FILE "scores.txt"
#define MAX_NAME_LENGTH 50

void wordhunt();
void logic(char file_name[100], int *score);
int same(char text1[], char text2[]);
void str_to_upper(char str[]);
void save_score(char name[], int score);
void show_scores();

char player_name[MAX_NAME_LENGTH];

// Clear the console screen
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void wordhunt() {
    int score = 0;  // Initialize score to 0 for a new session
    int choice;

    // Ask for player name
    clear_screen();
    printf("Enter your name: ");
    fgets(player_name, MAX_NAME_LENGTH, stdin);
    player_name[strcspn(player_name, "\n")] = '\0';  // Remove newline

    while (1) {
        clear_screen();
        printf("WELCOME TO WORD HUNT, %s!\n\n", player_name);
        printf("Current Score: %d\n\n", score);
        printf("Please select the difficulty:\n\n");
        printf("\t1. EASY\n\t2. MEDIUM\n\t3. HARD\n\t4. How to play\n\t5. Save score\n\t6. Show scores\n\t7. Exit\n\nYour choice: ");
        scanf("%d", &choice);
        getchar();  // Handle newline after scanf

        clear_screen();

        //Choosing options
        switch (choice) {
            case 1: // Launching easy level
                printf("\n\n\t\t***Easy Level***\n\n\tYour theme is Nature\n\n");
                game("easy_Nature.txt", &score);
                break;

            case 2: // Launching medium level
                printf("\n\n\t\t***Medium Level***\n\n\tYour theme is Professions\n\n");
                game("medium_Profession.txt", &score);
                break;

            case 3: // Launching hard level
                printf("\n\n\t\t***Hard Level***\n\n\tYour theme is Fantasy\n\n");
                game("hard_Fantasy.txt", &score);
                break;

            case 4:
                printf("Word Hunt is a game where you guess words based on a theme.\nYou have 5 attempts to guess each word.\n\nPress Enter to return to the menu.");
                getchar();
                break;

            case 5:
                if(score > 0)
                    save_score(player_name, score);
                else
                    printf("You havn't played the game yet to save your score.\n");
                printf("\nPress Enter to return to the menu.");
                getchar();
                break;

            case 6:
                show_scores();
                break;

            case 7:
                printf("\nThank you for playing Word Hunt, %s!\n", player_name);
                printf("\nSaving score...\n");
                save_score(player_name, score);  // Save the player's name and score
                printf("Your final score is: %d\n", score);
                return;

            default:
                printf("Invalid option! Please try again.\n");
                getchar();
        }
    }
}

void game(char file_name[100], int *score) {
    FILE *fptr = fopen(file_name, "r");

    if (fptr == NULL) {
        fprintf(stderr, "\nThe file is either corrupted or doesn't exist!\n");
        exit(1);
    }

    char word[20], guess[20];

    while (fgets(word, sizeof(word), fptr)) {
        word[strcspn(word, "\n")] = '\0';  // Remove newline

        int attempt = 5;
        while (attempt > 0) {
            clear_screen();
            printf("To return to the menu, type 'EXIT'.\n\n");
            printf("You have %d attempts left.\n\nGive your guess: ", attempt);
            scanf("%s", guess);
            getchar();  // Handle newline after input

            str_to_upper(guess);
            str_to_upper(word);

            if (strcmp(guess, "EXIT") == 0) {
                fclose(fptr);  // Close file before exiting logic
                return;
            } else if (same(guess, word) == 0) {
                printf("\n\nGreat job!\n");
                getchar();
                break;
            } else {
                printf("\n\nIncorrect!\n");
                --attempt;
                getchar();
            }
        }

        printf("\n\nThe correct word was: %s\n\n", word);
        *score += attempt;
        printf("Press Enter to continue to the next word...");
        getchar();
    }

    fclose(fptr);
}

// Save the player's name and score to a file
void save_score(char name[], int score) {
    FILE *fptr = fopen(SCORE_FILE, "a");  // Open for appending
    if (fptr == NULL) {
        fprintf(stderr, "Error saving score!\n");
        return;
    }
    fprintf(fptr, "%s - %d\n", name, score);
    fclose(fptr);
}

// Show all stored scores
void show_scores() {
    FILE *fptr = fopen(SCORE_FILE, "r");
    if (fptr == NULL) {
        printf("No scores available yet.\n\nPress Enter to return to the menu.");
        getchar();
        return;
    }

    char line[100];
    printf("\nHigh Scores:\n\n");
    while (fgets(line, sizeof(line), fptr)) {
        printf("%s", line);
    }
    fclose(fptr);

    printf("\nPress Enter to return to the menu.");
    getchar();
}

// Compare two strings
int same(char text1[], char text2[]) {
    return strcmp(text1, text2);
}

// Convert a string to uppercase
void str_to_upper(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    wordhunt();
    return 0;
}
