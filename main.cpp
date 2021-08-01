/**********************************************************
 * AUTHORS   : Ellen Yim & Tian Liu
 * Lab #4    : Stacks - N Queens
 * CLASS     : CS 008
 * SECTION   : Mon & Wed 6:30pm-8:35pm
 * Due Date  : 3/27/21
 *********************************************************/
#include <vector>
#include <iostream>
using namespace std;
/**********************************************************
 *
 * N_Queens
 *
 * -------------------------------------------------------
 *
 * -------------------------------------------------------
 * INPUT:
 *
 * OUTPUT:
 *
***********************************************************/


// To find all solutions for n-queens:
void backtrack(vector<int>& s, int curr_row, int n);
bool construct(const vector<int>& s, int row, int n, vector<int>& candidates);
bool is_square_safe(const vector<int>& s, int row, int col);
bool is_solution(const vector<int>& s, int n);
void print_solutions(vector<int>& s, int n);


int main()
{
    int n;    // IN - number of queens

    while (true)
    {
        cout << "Enter number of queens (<1 to exit): ";
        cin >> n;
        cout << endl;
        vector<int> queens = vector<int>();

        if (n > 0) {
            cout << "\n---------- All solutions ---------- " << endl;
            backtrack(queens, 0, n);
        } else
            break;

        cout << endl;
    }

    return 0;
}

/******************************************************
 * void backtrack(vector<int>& s, int curr_row, int n)
 *
 * ---------------------------------------------------
 * finding all (or some) solutions to some computational
 * problem, that incrementally builds candidates to the
 * solutions
 * ---------------------------------------------------
 *      PARAMETERS: dynamically int array, current row
 *      n size of queens
 * ---------------------------------------------------
 *      RETURNS: none
*******************************************************/
void backtrack(vector<int>& s, int curr_row, int n)
{
    if (is_solution(s, n)) {
        print_solutions(s, n);
    } else {
        vector<int> candidates = vector<int>();
        if (construct(s, curr_row, n, candidates)) {
            for (size_t i = 0; i < candidates.size(); ++i) {
                // push to particular solution, continue
                s.push_back(candidates[i]);
                backtrack(s, curr_row + 1, n);
                // if no feasible solution found, remove
                s.pop_back();
            }
        }
    }
}

/******************************************************
 * bool construct_candidates(const vector<int>&, int, int,
 *                      vector<int>&)
 *
 * ---------------------------------------------------
 * if square is safe to put a queen, then candidate will
 * hold onto the position. returns if size of candidates
 * is greater than 0
 * ---------------------------------------------------
 *      PARAMETERS: dynamically int array, row and n
 *      as int, dynamically int array to store candidates
 * ---------------------------------------------------
 *      RETURNS: bool
*******************************************************/
bool construct(const vector<int>& s, int row, int n,
                          vector<int>& candidates)
{
    for (int i = 0; i < n; ++i) {
        if (is_square_safe(s, row, i)) {
            candidates.push_back(i);
        }
    }
    return candidates.size() > 0;
}

/******************************************************
 * bool is_square_safe(const vector<int>&, int, int)
 *
 * ---------------------------------------------------
 * checks if the square position is safe to place a
 * queen
 * ---------------------------------------------------
 *      PARAMETERS: dynamically int array, int row&col
 * ---------------------------------------------------
 *      RETURNS: bool
*******************************************************/
bool is_square_safe(const vector<int>& s, int row, int col)
{
    for (int i = 0; i < s.size(); ++i) {
        if (i==row || s[i] == col) return false;
        if (abs(i-row) == abs(s[i]-col)) return false;
    }
    return true;
}

/******************************************************
 * bool is_solution(vector<int>& s, int n)
 *
 * ---------------------------------------------------
 * returns true if dynamic int array size equals n-queens
 * ---------------------------------------------------
 *      PARAMETERS: dynamic int array, n size of queens
 * ---------------------------------------------------
 *      RETURNS: bool
*******************************************************/
bool is_solution(const vector<int>& s, int n)
{
    return (s.size() == n);
}

/******************************************************
 * print_solution(vector<int>& s, int n)
 *
 * ---------------------------------------------------
 *  If found all the solutions, it displays the
 *  board.
 * ---------------------------------------------------
 *      PARAMETERS:
 * ---------------------------------------------------
 *      RETURNS: none
*******************************************************/
void print_solutions(vector<int>& s, int n)
{
    int i;
    int j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (s[i] == j) cout << "Q ";
            else cout << "# ";
        }
        cout << "\n";
    }
    cout << "\n";
}

