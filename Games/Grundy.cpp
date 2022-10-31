// A function to Compute Grundy Number of 'n' 
// Only this function varies according to the game 
int calculateGrundy(int n) { 
    if (n == 0) 
        return (0); 
    unordered_set<int> Set; // A Hash Table 
    for (int i=0; i<=n-1; i++) 
            Set.insert(calculateGrundy(i)); 
    return (calculateMex(Set)); 
}