//Given a 2D integer array matrix, return the transpose of matrix. The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

int** transpose(int** matrix, int matrixSize, int* matrixColSize, 
                int* returnSize, int** returnColumnSizes) {
    
    int rows = matrixSize;              // original rows
    int cols = matrixColSize[0];        // original columns
    
    // Transposed matrix will have:
    // rows = cols
    // cols = rows
    
    *returnSize = cols;
    
    // Allocate memory for column sizes of result
    *returnColumnSizes = (int*)malloc(cols * sizeof(int));
    
    for (int i = 0; i < cols; i++) {
        (*returnColumnSizes)[i] = rows;
    }
    
    // Allocate memory for result matrix
    int** result = (int**)malloc(cols * sizeof(int*));
    
    for (int i = 0; i < cols; i++) {
        result[i] = (int*)malloc(rows * sizeof(int));
    }
    
    // Fill transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    
    return result;
}