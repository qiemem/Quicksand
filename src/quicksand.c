#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void fillSandpile(int rows, int cols, int sandpile[][cols], int grains) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			sandpile[i][j] = grains;
		}
	}
}

void printSandpile(int rows, int cols, int sandpile[][cols]) {
	for (int i = 0; i < rows; i++) {
		printf("%d", sandpile[i][0]);
		for (int j = 1; j < cols; j++) {
			printf(",%d", sandpile[i][j]);
		}
		printf("\n");
	}
}

bool updateSandpile(int rows, int cols, int sandpile[][cols]) {
	bool unstable = false;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (sandpile[i][j] > 3) {
				sandpile[i][j] -= 4;
				if (i > 0) sandpile[i-1][j]++;
				if (i < (rows-1)) sandpile[i+1][j]++;
				if (j > 0) sandpile[i][j-1]++;
				if (j < (cols-1)) sandpile[i][j+1]++;
				unstable = true;
			}
		}
	}
	return unstable;
}

int main(int argc, char *argv[]) {
	int rows = atoi(argv[1]), cols = atoi(argv[2]), grains = atoi(argv[3]);
	int sandpile[rows][cols];
	fillSandpile(rows, cols, sandpile, grains);
	while (updateSandpile(rows, cols, sandpile));
	printSandpile(rows, cols, sandpile);
	return 0;
}
