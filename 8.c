#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

int N;
int SIZE;
char **grid;
//usei ia mermo julio e fds//
void draw_line(double x0, double y0, double x1, double y1) {
    int steps = (int)(sqrt((x1-x0)*(x1-x0) + (y1-y0)*(y1-y0)) * 2) + 1;
    if (steps < 1) steps = 1;
    for (int i = 0; i <= steps; i++) {
        double t = (double)i / steps;
        int cx = (int)round(x0 + t * (x1 - x0));
        int cy = (int)round(y0 + t * (y1 - y0));
        if (cx >= 0 && cx < SIZE && cy >= 0 && cy < SIZE)
            grid[cy][cx] = '*';
    }
}

void koch_line(double x0, double y0, double x1, double y1, int depth) {
    if (depth == 0) {
        draw_line(x0, y0, x1, y1);
        return;
    }
    double dx = x1 - x0, dy = y1 - y0;
    double ax = x0 + dx/3, ay = y0 + dy/3;
    double bx = x0 + 2*dx/3, by = y0 + 2*dy/3;
    double mx = (x0+x1)/2 - (dy)*sqrt(3)/6;
    double my = (y0+y1)/2 + (dx)*sqrt(3)/6;
    koch_line(x0, y0, ax, ay, depth-1);
    koch_line(ax, ay, mx, my, depth-1);
    koch_line(mx, my, bx, by, depth-1);
    koch_line(bx, by, x1, y1, depth-1);
}

void draw_snowflake() {
    double cx = SIZE / 2.0;
    double cy = SIZE / 2.0;
    double R = SIZE * 0.38;

    // Seis pontas da estrela (dois triângulos sobrepostos)
    // Triângulo 1: aponta para cima
    double t1x[3], t1y[3];
    // Triângulo 2: aponta para baixo
    double t2x[3], t2y[3];

    for (int i = 0; i < 3; i++) {
        double angle1 = PI/2 + i * 2*PI/3;
        t1x[i] = cx + R * cos(angle1);
        t1y[i] = cy - R * sin(angle1);

        double angle2 = PI/2 + PI/3 + i * 2*PI/3;
        t2x[i] = cx + R * cos(angle2);
        t2y[i] = cy - R * sin(angle2);
    }

    // Desenha os 6 lados com Koch
    for (int i = 0; i < 3; i++) {
        int j = (i+1) % 3;
        koch_line(t1x[i], t1y[i], t1x[j], t1y[j], N);
        koch_line(t2x[i], t2y[i], t2x[j], t2y[j], N);
    }
}

int main() {
    system("clear");

    do {
        printf("Digite o nivel N do fractal (1 <= N <= 3): ");
        scanf("%d", &N);
        if (N < 1 || N > 3)
            printf("Valor invalido! N deve ser entre 1 e 3.\n");
    } while (N < 1 || N > 3);

    // Tamanho cresce com o nível
    SIZE = 40 + N * 40;

    // Aloca grid
    grid = (char **)malloc(SIZE * sizeof(char *));
    for (int i = 0; i < SIZE; i++) {
        grid[i] = (char *)malloc((SIZE + 1) * sizeof(char));
        memset(grid[i], ' ', SIZE);
        grid[i][SIZE] = '\0';
    }

    draw_snowflake();

    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        // Remove espaços à direita
        int last = SIZE - 1;
        while (last >= 0 && grid[i][last] == ' ') last--;
        grid[i][last+1] = '\0';
        printf("%s\n", grid[i]);
    }

    for (int i = 0; i < SIZE; i++) free(grid[i]);
    free(grid);

    return 0;
}