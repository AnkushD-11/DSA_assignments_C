// Tower of Hanoi using C 

#include <stdio.h>

void TOH(int n, char source, char mid, char dest) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }
    
    TOH(n - 1, source, dest, mid);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    TOH(n - 1, mid, source, dest);
}

int main() {
    int bricks;
    
    printf("Enter the number of disks: ");
    scanf("%d", &bricks);
    
    TOH(bricks, 'A', 'B', 'C');
    
    return 0;
}
