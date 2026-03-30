#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define NUM_THEMES 6
#define MAX_STARS 100

typedef struct {
    char *name;
    const char *color;
} Theme;

Theme themes[NUM_THEMES] = {
    {"RETRO", "\033[0;33m"}, // Yellow
    {"NEON", "\033[0;35m"},  // Magenta
    {"COSMIC", "\033[0;34m"},// Blue
    {"AURORA", "\033[1;32m"},// Green
    {"MATRIX", "\033[0;32m"},// Dark Green
    {"CYBERPUNK", "\033[1;35m"} // Bright Magenta
};

void display_help() {
    printf("Help Menu:\n");
    printf("1. Choose a theme by entering a number from 1 to %d.\n", NUM_THEMES);
    printf("2. Adjust speed by changing the delay between stars.\n");
    printf("3. Press 'q' to quit the starfield.\n");
}

void starfield(int speed, int theme_index) {
    while (1) {
        for (int i = 0; i < MAX_STARS; i++) {
            printf("%s*", themes[theme_index].color);
            fflush(stdout);
            usleep(speed);
            printf("\033[1D \033[0m"); // Erase the last star
        }
        if (getchar() == 'q') break; // Exiting condition
    }
}

int main() {
    int speed = 100000; // Default speed
    int theme_choice;

    display_help();

    printf("Select a theme (1 - %d): ", NUM_THEMES);
    scanf("%d", &theme_choice);
    theme_choice--; // Adjust index

    if (theme_choice < 0 || theme_choice >= NUM_THEMES) {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Adjust speed (μs, default is 100000): ");
    scanf("%d", &speed);

    printf("\033[0m"); // Reset color
    starfield(speed, theme_choice);

    return 0;
}