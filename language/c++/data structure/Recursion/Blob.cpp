/** Program that solves problem of counting abnormal cells. */

enum color {BACKGROUND, ABNORMAL, TEMPORARY};
const int ROW_SIZE = 5;
const int COL_SIZE = 5;

// Insert main function here.
#include <iostream>
int count_cells(color[ROW_SIZE][COL_SIZE], int, int);
int main() {
  color grid[ROW_SIZE][COL_SIZE] =
      {{BACKGROUND, ABNORMAL, BACKGROUND, ABNORMAL, ABNORMAL},
       {BACKGROUND, ABNORMAL, BACKGROUND, BACKGROUND, ABNORMAL},
       {BACKGROUND, BACKGROUND, BACKGROUND, ABNORMAL, BACKGROUND},
       {BACKGROUND, ABNORMAL, BACKGROUND, BACKGROUND, BACKGROUND},
       {BACKGROUND, ABNORMAL, BACKGROUND, ABNORMAL, BACKGROUND}};

  // Enter row and column of a cell in the blob.
  int row;
  std::cout << "Enter row: ";  std::cin >> row;
  int col;
  std::cout << "Enter column: ";  std::cin >> col;

  // Display results.
  std::cout << count_cells(grid, row, col) << "\n";
}

/** Finds the number of cells in the blob that contains grid[r][c].
    pre:  Abnormal cells are in ABNORMAL color;
          Other cells are in BACKGROUND color.
    post: All cells in the blob are in the TEMPORARY color.
    @param r The row of a blob cell
    @param c The column of a blob cell
    @return The number of cells in the blob that contains grid[r][c]
*/
int count_cells(color grid[ROW_SIZE][COL_SIZE], int r, int c) {

  if (r < 0 || r >= ROW_SIZE || c < 0 || c >= COL_SIZE) {
      return 0;
  }
  else if (grid[r][c] != ABNORMAL) {
      return 0;
  }
  else {
    grid[r][c] = TEMPORARY;
return 1
  + count_cells(grid, r - 1, c - 1) + count_cells(grid, r - 1, c)
  + count_cells(grid, r - 1, c + 1) + count_cells(grid, r, c + 1)
  + count_cells(grid, r + 1, c + 1) + count_cells(grid, r + 1, c)
  + count_cells(grid, r + 1, c - 1) + count_cells(grid, r, c - 1);
  }
}
