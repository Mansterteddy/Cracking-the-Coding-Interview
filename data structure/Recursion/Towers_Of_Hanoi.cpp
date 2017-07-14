
#include <iostream>
using namespace std;

void show_moves(int n, char startPeg,
	       char destPeg, char tempPeg);

int main() {
  int n_disks;
  char start_peg;
  char dest_peg;
  char temp_peg;
  cout << "Enter number of disks: ";
  cin >> n_disks;
  cout << "Enter start peg: ";
  cin >> start_peg;
  cout << "Enter destination peg: ";
  cin >> dest_peg;
  cout << "Enter temporary peg: ";
  cin >> temp_peg;
  show_moves(n_disks, start_peg, dest_peg, temp_peg);
}

/** Recursive function for "moving" disks.
    pre: start_peg, dest_peg, temp_peg are different, n >= 1.
    post: displays a list of moves that solve the problem
          of moving n disks from start_peg to dest_peg.
    @param n is the number of disks
    @param start_peg is the starting peg
    @param dest_peg is the destination peg
    @param temp_peg is the temporary peg
    @return A string with all the required disk moves
*/
void show_moves(int n, char start_peg,
                char dest_peg, char temp_peg) {
  if (n == 1)
  {
    cout << "Move disk 1 from peg " << start_peg
            << " to peg " << dest_peg << "\n";
  }
  else
  {  // Recursive step
    show_moves(n - 1, start_peg, temp_peg, dest_peg);
    cout << "Move disk " << n << " from peg " << start_peg
         << " to peg " << dest_peg << "\n";
    show_moves(n - 1, temp_peg, dest_peg, start_peg);
  }
}
