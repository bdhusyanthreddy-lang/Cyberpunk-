# Makefile

# Variables
CC=gcc
CFLAGS=-Wall -Wextra -O2

# Targets
all: basic_unix advanced_unix themes_unix basic_windows advanced_windows themes_windows

# Compile basic starfield variant for Unix
basic_unix: basic_unix.o
	$(CC) $(CFLAGS) -o basic_unix basic_unix.o

# Compile advanced starfield variant for Unix
advanced_unix: advanced_unix.o
	$(CC) $(CFLAGS) -o advanced_unix advanced_unix.o

# Compile themes version for Unix
themes_unix: themes_unix.o
	$(CC) $(CFLAGS) -o themes_unix themes_unix.o

# Compile basic starfield variant for Windows
basic_windows: basic_windows.o
	$(CC) $(CFLAGS) -o basic_windows.exe basic_windows.o

# Compile advanced starfield variant for Windows
advanced_windows: advanced_windows.o
	$(CC) $(CFLAGS) -o advanced_windows.exe advanced_windows.o

# Compile themes version for Windows
themes_windows: themes_windows.o
	$(CC) $(CFLAGS) -o themes_windows.exe themes_windows.o

# Clean up
clean:
	rm -f *.o basic_unix advanced_unix themes_unix basic_windows.exe advanced_windows.exe themes_windows.exe
