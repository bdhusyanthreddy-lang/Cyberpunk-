#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define MAX_STARS 100
#define WIDTH 80
#define HEIGHT 25

typedef struct {
    int x, y;
    int color;
    double speed;
} Star;

Star stars[MAX_STARS];
double starSpeed = 1.0;
int running = 1;

void initializeStars() {
    for (int i = 0; i < MAX_STARS; i++) {
        stars[i].x = rand() % WIDTH;
        stars[i].y = rand() % HEIGHT;
        stars[i].color = rand() % 15 + 1; // 1 to 15 for colors
        stars[i].speed = starSpeed;
    }
}

void drawStars() {
    system("cls"); // clear the screen
    for (int i = 0; i < MAX_STARS; i++) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), stars[i].color);
        printf("%c", '*');
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // reset to default
}

void updateStars() {
    for (int i = 0; i < MAX_STARS; i++) {
        stars[i].y += stars[i].speed;
        if (stars[i].y >= HEIGHT) {
            stars[i].y = 0;
            stars[i].x = rand() % WIDTH;
            stars[i].color = rand() % 15 + 1;
        }
    }
}

void displayHelp() {
    printf("Controls:\n");
    printf("Up Arrow: Increase speed\n");
    printf("Down Arrow: Decrease speed\n");
    printf("Space: Pause/Resume\n");
    printf("H: Help\n");
    printf("Esc: Exit\n");
}

int main() {
    initializeStars();
    displayHelp();

    while (running) {
        if (_kbhit()) { // check if a key is pressed
            char ch = _getch();
            switch (ch) {
                case 72: starSpeed += 0.1; break; // up arrow
                case 80: starSpeed -= 0.1; break; // down arrow
                case 32: running = !running; break; // space
                case 'H': case 'h': displayHelp(); break; // help
                case 27: running = 0; break; // escape
            }
        }

        if (running) {
            updateStars();
            drawStars();
            Sleep(100); // adjust for speed
        }
    }

    return 0;
}