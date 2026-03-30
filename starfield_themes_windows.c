// starfield_themes_windows.c

#include <stdio.h>

void applyTheme(const char* themeName) {
    if (strcmp(themeName, "dark") == 0) {
        // Apply dark theme
        printf("Applying Dark Theme...\n");
    } else if (strcmp(themeName, "light") == 0) {
        // Apply light theme
        printf("Applying Light Theme...\n");
    } else if (strcmp(themeName, "blue") == 0) {
        // Apply blue theme
        printf("Applying Blue Theme...\n");
    } else {
        printf("Theme not recognized.\n");
    }
}

int main() {
    // Example usage
    applyTheme("dark"); // Change this to test different themes
    return 0;
}