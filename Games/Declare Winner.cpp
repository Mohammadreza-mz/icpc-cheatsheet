void declareWinner(int whoseTurn, int piles[], int Grundy[], int n) { 
    int xorValue = Grundy[piles[0]]; 
    for (int i=1; i<=n-1; i++) 
        xorValue = xorValue ^ Grundy[piles[i]]; 
    if (xorValue != 0) { 
        if (whoseTurn == PLAYER1) 
            printf("Player 1 will win\n"); 
        else
            printf("Player 2 will win\n"); 
    } 
    else { 
        if (whoseTurn == PLAYER1) 
            printf("Player 2 will win\n"); 
        else
            printf("Player 1 will win\n"); 
    } 
    return; 
} 
  