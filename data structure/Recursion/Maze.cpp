/** Program that solves maze problems with backtracking. */

enum color {BACKGROUND, ABNORMAL, TEMPORARY, PATH};
const int ROW_SIZE = 5;
const int COL_SIZE = 5;
// Insert main function here
#include <iostream>
bool find_maze_path(color[ROW_SIZE][COL_SIZE]);
bool find_maze_path(color[ROW_SIZE][COL_SIZE], int r, int c);
int main() {
  color grid[ROW_SIZE][COL_SIZE] =
      {{BACKGROUND, ABNORMAL, BACKGROUND, ABNORMAL, ABNORMAL},
       {BACKGROUND, ABNORMAL, BACKGROUND, ABNORMAL, ABNORMAL},
       {BACKGROUND, BACKGROUND, BACKGROUND, ABNORMAL, BACKGROUND},
       {BACKGROUND, ABNORMAL, BACKGROUND, BACKGROUND, BACKGROUND},
       {BACKGROUND, ABNORMAL, BACKGROUND, ABNORMAL, BACKGROUND}};

  // Display results.
  std::cout << std::boolalpha << find_maze_path(grid) << "\n";
}

/** Wrapper function. */
bool find_maze_path(color grid[ROW_SIZE][COL_SIZE]) {
  return find_maze_path(grid, 0, 0);   // (0, 0) is the start point.
}

/** Attempts to find a path through cell grid[r][c].
    pre:  Possible path cells are in BACKGROUND color;
          barrier cells are in ABNORMAL color.
    post: If a path is found, all cells on it are set to the
          PATH color; all cells that were visited but are
          not on the path are in the TEMPORARY color.
    @param r The row of current point
    @param c The column of current point
    @return If a path through grid[r][c] is found, true;
            Otherwise, false
*/
bool find_maze_path(color grid[ROW_SIZE][COL_SIZE], int r, int c) {
  if (r < 0 || c < 0 || r >= ROW_SIZE || c >= COL_SIZE)
    return false;      // Cell is out of bounds.
  else if (grid[r][c] != BACKGROUND)
    return false;      // Cell is on barrier or dead end.
  else if (r == ROW_SIZE - 1 && c == COL_SIZE - 1) {
    grid[r][c] = PATH;         // Cell is on path
    return true;               // and is maze exit.
  }
  else { 
    // Recursive case.
    // Attempt to find a path from each neighbor.
    // Tentatively mark cell as on path.
    grid[r][c] = PATH;
    if (find_maze_path(grid, r - 1, c)
        || find_maze_path(grid, r + 1, c)
        || find_maze_path(grid, r, c - 1)
        || find_maze_path(grid, r, c + 1 ) ) {
      return true;
    }
    else {
      grid[r][c] = TEMPORARY;  // Dead end.
      return false;
    }
  }
}
