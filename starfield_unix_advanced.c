#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <termios.h>  
#include <fcntl.h>  
  
// Function to get non-blocking keyboard input  
int kbhit(void) {  
    struct termios oldt, newt;  
    int oldf;  
    int ch;  
    int oldf;  
  
    tcgetattr(STDIN_FILENO, &oldt);  
    newt = oldt;  
    newt.c_lflag &= ~(ICANON | ECHO);  
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);  
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);  
  
    ch = getchar();  
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  
    fcntl(STDIN_FILENO, F_SETFL, oldf);  
  
    if(ch != EOF) {  
        ungetc(ch, stdin);  
        return 1;  
    }  
    return 0;  
}  
  
// Function to set cursor position  
void gotoxy(int x, int y) {  
    printf("\033[%d;%dH", y, x);  
}  
  
// Function to clear the terminal  
void clear_screen() {  
    printf("\033[H\033[J");  
}  
  
// Function to generate random color  
char* random_color() {  
    static char color[8];  
    sprintf(color, "\033[38;5;%dm", rand() % 256);  
    return color;  
}  
  
// Function to display stars  
void display_stars(int speed, int color_mode) {  
    int width, height;  
    int star_count = 100;  
    char* color;  
    while(1) {  
        clear_screen();  
        for (int i = 0; i < star_count; i++) {  
            int x = rand() % width;  
            int y = rand() % height;  
            if (color_mode == 0) {  
                color = "\033[37m";  
            } else if (color_mode == 1) {  
                color = random_color();  
            } else {  
                color = random_color();  
            }  
            gotoxy(x, y);  
            printf("%s*\033[0m", color);  
        }  
        usleep(1000000 / speed);  
        if (kbhit()) break;  
    }  
}  
  
int main() {  
    int speed = 5;  
    int color_mode = 0;  
    char command;  
    while(1) {  
        display_stars(speed, color_mode);  
        printf("\033[0;0HSpeed: %d Color Mode: %d\n", speed, color_mode);  
        printf("Press 'q' to quit, 'p' to pause, 'c' to change color mode\n");  
        if (kbhit()) {  
            command = getchar();  
            if (command == 'q') break;  
            if (command == 'p') {  
                while (!kbhit());  
                getchar();  
            }  
            if (command == 'c') {  
                color_mode = (color_mode + 1) % 3;  
            }  
        }  
    }  
    return 0;  
}  
