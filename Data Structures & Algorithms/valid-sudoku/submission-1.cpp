class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        
        
        bool r[9][9] = {false}, c[9][9] = {false}, bx[9][9] = {false};

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){

                if( b[i][j]=='.' ) continue;

                int v = b[i][j]-'1';

                int bn = (i/3)*3+(j/3);

                if( r[i][v] || c[j][v] || bx[bn][v] ) return false;

                r[i][v] = c[j][v] =  bx[bn][v] = true;

            }
        }
        return true;
    }
};
