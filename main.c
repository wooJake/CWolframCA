#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    int rule[8] = {0,0,0,1,1,1,1,0};
    int posits[8][3] = {{1,1,1},{1,1,0},{1,0,1},{1,0,0},{0,1,1},{0,1,0},{0,0,1},{0,0,0}};
    
    srand(time(NULL));
    
    const int length = 65;
    
    int board[length];
    int board2[length];
    
    for(int i = 0; i < length; ++i){
        
        board[i] = 0;
        board2[i] = board[i];
    }
    
    board[length / 2] = 1;
    board2[length / 2] = board[length / 2];
    
    int loop = 0;
    
    while(loop < 256){
        
        for(int i = 0; i < length; ++i){
            
            int aDiff = i == 0 ? length - 1 : -1;
            int bDiff = i == length - 1 ? -length + 1 : 1;
            
            for(int j = 0; j < 8; ++j){
                
                    
                if(posits[j][0] == board[i + aDiff] &&
                    posits[j][1] == board[i] &&
                    posits[j][2] == board[i + bDiff]){
                    
                    board2[i] = rule[j];
                    break;
                }
            }
        }
        for(int i = 0; i < length; ++i){
            
            board[i] = board2[i];
            
            if(board[i] == 1){
                
                printf("@");
            }
            else{
                
                printf(" ");
            }
        }
        printf("\n");
        
        ++loop;
    }

    return 0;
}
