#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void fill_sandpile(int rows, int cols, int sandpile[][cols], int grains) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			sandpile[i][j] = grains;
		}
	}
}

void print_sandpile(int rows, int cols, int sandpile[][cols]) {
	char symbols[] = " .*#456789000000000000000000";
	for (int i = 0; i < rows; i++) {
		//printf("%d", sandpile[i][0]);
		printf("%c%c", symbols[sandpile[i][0]],symbols[sandpile[i][0]]);
		for (int j = 1; j < cols; j++) {
			//printf(",%d", sandpile[i][j]);
			printf("%c%c", symbols[sandpile[i][j]],symbols[sandpile[i][j]]);
		}
		printf("\n");
	}
}

bool update_sandpile(int rows, int cols, int sandpile[][cols]) {
	int last_state[rows][cols];
	memcpy(last_state, sandpile, rows*cols*sizeof(int));
	bool unstable = false;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (last_state[i][j] > 3) {
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

void get_identity(int rows, int cols, int sandpile[rows][cols]) {
	fill_sandpile(rows, cols, sandpile, 6);
	while (update_sandpile(rows, cols, sandpile));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			sandpile[i][j] = 6 - sandpile[i][j];
		}
	}
	while (update_sandpile(rows, cols, sandpile));
}

int main(int argc, char *argv[]) {
	int rows = atoi(argv[1]), cols = atoi(argv[2]);
	int sandpile[rows][cols];
	get_identity(rows, cols, sandpile);
	print_sandpile(rows, cols, sandpile);
	return 0;
}
