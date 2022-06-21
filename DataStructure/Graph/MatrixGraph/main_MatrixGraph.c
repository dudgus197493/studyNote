#include<stdio.h>
#include<stdlib.h>

// 인접행렬 구현
int** makeGraphMatrix(int _columnSize, int _rowSize) {
	int** ppArray = (int**)malloc(sizeof(int*) * _columnSize);

	for (int i = 0; i < _rowSize; i++) {
		ppArray[i] = (int*)malloc(sizeof(int) * _rowSize);

		memset(ppArray[i], 0, sizeof(int) * _rowSize);

		/*for (int j = 0; j < _rowSize; j++) {
			ppArray[i][j] = 0;
		}*/
	}

	return ppArray;
}

// 정점 추가
void matrixAddEdge(int** _ppGraph, int _index1, int _index2) {
	_ppGraph[_index1 - 1][_index2 - 1] = 1;
}

// 인정행렬 출력
void printMatrixGraph(int** _ppGraph, int _columnSize, int _rowSize) {

	/*for (int i = 0; i < _columnSize; i++) {
		for (int j = 0; j < _rowSize; j++) {
			printf("%d ", _ppGraph[i][j]);
		}
		printf("\n");
	}*/


	for (int i = 0; i < _columnSize; i++) {
		printf("%d : ", i + 1);
		for (int j = 0; j < _rowSize; j++) {
			if (_ppGraph[i][j] == 1) {
				printf("%d[0] ", j + 1);
			}
		}
		printf("\n");
	}
}
void destroyMatrixGraph(int** _ppGraph, int _rowSize) {
	for (int i = 0; i < _rowSize; i++) {
		free(_ppGraph[i]);
	}
	free(_ppGraph);
}



int main() {
	int** matrix = makeGraphMatrix(5, 5);
	matrixAddEdge(matrix, 1, 2);
	matrixAddEdge(matrix, 1, 3);
	matrixAddEdge(matrix, 1, 4);
	matrixAddEdge(matrix, 1, 5);

	matrixAddEdge(matrix, 2, 1);
	matrixAddEdge(matrix, 2, 3);
	matrixAddEdge(matrix, 2, 5);

	matrixAddEdge(matrix, 3, 1);
	matrixAddEdge(matrix, 3, 2);

	matrixAddEdge(matrix, 4, 1);
	matrixAddEdge(matrix, 4, 5);

	matrixAddEdge(matrix, 5, 1);
	matrixAddEdge(matrix, 5, 2);
	matrixAddEdge(matrix, 5, 4);

	printMatrixGraph(matrix, 5, 5);

	destroyMatrixGraph(matrix, 5);

	printf("인접행렬이 소멸되었습니다.");

	return 0;
}