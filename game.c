#include <stdio.h>
#include <math.h>
#include <unistd.h>  // for usleep function

float zbuffer[80 * 25];  // Assuming zbuffer is declared and initialized somewhere in your code

void drawDonut(float a, float b) {
    // ... (unchanged)
}

void delay(int milliseconds) {
    usleep(milliseconds * 1000);  // sleep in microseconds
}

int main() {
    for (int i = 0; i < 80 * 25; i++) {
        zbuffer[i] = 0;
    }

    for (float t = 0; t < 500; t += 0.1) {
        float a = t;
        float b = t / 2;

        drawDonut(a, b);

        delay(50);
        printf("\033[H\033[J");  // ANSI escape code to clear the screen
    }

    return 0;
}
