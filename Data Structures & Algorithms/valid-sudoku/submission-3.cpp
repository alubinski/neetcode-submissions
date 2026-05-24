class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    int rows[9]{};
    int cols[9]{};
    int squares[9]{};

    for (int r{}; r < 9; ++r) {
      for (int c{}; c < 9; ++c) {
        if (board[r][c] == '.')
          continue;

        int val{board[r][c] - '1'};

        if ((rows[r] & (1 << val)) || (cols[c] & (1 << val)) ||
            (squares[(r / 3) * 3 + (c / 3)] & (1 << val)))
          return false;

        rows[r] |= (1 << val);
        cols[c] |= (1 << val);
        squares[(r / 3) * 3 + (c / 3)] |= (1 << val);
      }
    }

    return true;
  }
};