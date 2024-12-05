#include <ncurses.h>
#include <stdio.h>

int main() {
    char ch;
    ch = getch();
    printf("ch=%c", ch);
}