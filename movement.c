#include <stdio.h>

int main() {
    
    /* TODO: Implement here */
    char path;
    int x, y, N;
    scanf("%c %d %d %d", &path, &x, &y, &N);
    /* like a compass N -> E -> S -> W -> N
    since we start at 0 and go to N-1 as defined in the problem
    and y increases with S and x increases with E then we check N-1
    at these and 0 at others for movement.*/
    switch (path) {
        case 'N':
            if (y > 0) y--;
            break;
        case 'E':
            if (x < N - 1) x++;
            break;
        case 'S':
            if (y < N - 1) y++;
            break;
        case 'W':
            if (x > 0) x--;
            break;

    }
    printf("%d %d\n", x, y);
    
    
    return 0;
}
