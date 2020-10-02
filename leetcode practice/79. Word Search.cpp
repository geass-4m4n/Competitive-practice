class Solution {
public:
    
      bool isFound(vector<vector<char>>& board, int i, int j, string word, int index) 
      {
        if(index == word.length()) return true;
          
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if(word[(index)] != board[i][j]) return false;
        char temp = board[i][j];
        board[i][j] = '*';
          
          
        if(isFound(board, i + 1, j, word, index + 1) ||
            isFound(board, i - 1, j, word, index + 1) ||
            isFound(board, i, j + 1, word, index + 1) ||
            isFound(board, i, j - 1, word, index + 1))
            return true;
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
                for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(board[i][j] == word[0] && isFound(board, i, j, word, 0))
                    return true;
        
        return false;

        
    }
};
