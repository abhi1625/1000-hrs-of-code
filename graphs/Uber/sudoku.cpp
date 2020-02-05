bool sudoku2(std::vector<std::vector<char>> grid) {
    for (char c = '1'; c <= '9'; ++c) {
        for (int i = 0; i < 9; ++i) {
            int c1 = 0, c2 = 0, c3 = 0;
            for (int j = 0; j < 9; ++j) {
                c1 += grid[i][j] == c;
                c2 += grid[j][i] == c;
                c3 += grid[i/3*3+j/3][i%3*3+j%3] == c;
            }
            if (c1 > 1 || c2 > 1 || c3 > 1)
                return false;
        }
    }
    return true;
}
