#include<stdio.h>

int main(){

    int n;

    scanf("%d", &n);

    int e[n][n];

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            scanf("%d", &e[i][j]);
        }
    }

    int achou = 0;
    int rot = 0;

    while (rot < 4 && !achou) {
        int cresc = 1;
        int i = 0;

        while (cresc && (i + 1) < n) {

            int j = 0;

            while (cresc && (j + 1) < n) {

                if ((rot == 0 || rot == 3) && e[i][j] > e[i][j+1])
                    cresc = 0;
                else if ((rot == 1 || rot == 2) && e[i][j] < e[i][j+1])
                    cresc = 0;

                j++;

                if (rot < 2 && e[i][0] > e[i+1][0])
                    cresc = 0;
                else if (rot >= 2 && e[i][0] < e[i+1][0])
                    cresc = 0;
            }

            i++;
        }

        if (cresc)
            achou = 1;
        else
            rot++;
    }

    printf("%d", rot);

    return 0;
}