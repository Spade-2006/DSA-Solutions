class Solution {
    public boolean exist(char[][] board, String word) {
        int rows = board.length;
        int cols = board[0].length;
        boolean[][] visited = new boolean[rows][cols];
        char[] w = word.toCharArray();

        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                if (exist(board, visited, y, x, w, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean exist(char[][] board, boolean[][] visited, int y, int x, char[] word, int i) {
        if (i == word.length) return true;
        if (y < 0 || x < 0 || y == board.length || x == board[y].length) return false;
        if (visited[y][x] || board[y][x] != word[i]) return false;

        visited[y][x] = true;

        boolean found = exist(board, visited, y, x + 1, word, i + 1)
                     || exist(board, visited, y, x - 1, word, i + 1)
                     || exist(board, visited, y + 1, x, word, i + 1)
                     || exist(board, visited, y - 1, x, word, i + 1);

        visited[y][x] = false; 
        return found;
    }
}