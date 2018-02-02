#include <stdio.h>
#include <stdlib.h>

/**
 * @author Dustin Fraser
 * @date 01/19/2018
 * @description: Blocking zombies
*/ 

void set_zombies(int n, char fred[n][n]) {

	int i, j;
	int r, c;



	while( scanf("%d", &r) == 1 ) {

		scanf("%d", &c);

		fred[r][c] = 'Z';

	}

}


void print_zombies(int n, char fred[n][n]) {

	int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c ", fred[i][j]);
        }
        printf("\n");
    }

}


void block_zombies(int n, char fred[n][n]) {

	int i;
	int j;
	char temp[n+2][n+2];
	
	for(j = 0; j < n+1; j++) {
		temp[0][j] = '.';
		temp[n+1][j] = '.';
	}

	for(i = 0; i < n+1; i++) {
		temp[i][0] = '.';
		temp[i][n+1] = '.';
	}

    for (i = 1; i < n+1; i++) {
        for (j = 1; j < n+1; j++) {
            temp[i][j] = fred[i-1][j-1];
        }
    }

    for (i = 0; i < n+1; i++) {
        for (j = 0; j < n+1; j++) {
            if (temp[i][j] == 'Z') {

				if ( temp[i+1][j] == '.') {
					temp[i+1][j] = 'B';
				} 

				if ( temp[i-1][j] == '.') {
					temp[i-1][j] = 'B';
				} 

				if ( temp[i][j+1] == '.') {
					temp[i][j+1] = 'B';
				} 

				if ( temp[i][j-1] == '.') {
					temp[i][j-1] = 'B';
				} 
				
			}
        }
    }

    for (i = 1; i < n+1; i++) {
        for (j = 1; j < n+1; j++) {
            fred[i-1][j-1] = temp[i][j];
        }
    }

}

int main() {

	int n, i, j;
	scanf("%d", &n);

	char fred[n][n];

	for(i = 0; i < n; i++) {
		for(j = 0; j < n+1; j++) {			
			fred[i][j] = '.';
		}
	}

	set_zombies(n, fred);
	printf("Original map \n");
	print_zombies(n, fred);
	block_zombies(n, fred);
	printf("\nMap with blocking info\n");
	print_zombies(n, fred);

} 
