int calculateMex(unordered_set<int> Set) { 
    int Mex = 0;
    while (Set.find(Mex) != Set.end()) 
        Mex++;  
    return (Mex); 
}