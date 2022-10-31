for (int s = 0; s<=k; s++)                    //s - length(size) of substring
    for (int L = 0; L+s<=k; L++) {              //L - left point
      int R = L + s;                            //R - right point
      if (s < 2) {                              
        res[L][R] = 0;                          //DP base - nothing to break
        mid[L][R] = l;                          //mid is equal to left border
        continue;
      }
      int mleft = mid[L][R-1];                  //Knuth's trick: getting bounds on M
      int mright = mid[L+1][R];
      res[L][R] = 1000000000000000000LL;
      for (int M = mleft; M<=mright; M++) {     //iterating for M in the bounds only
        int64 tres = res[L][M] + res[M][R] + (x[R]-x[L]);
        if (res[L][R] > tres) {                 //relax current solution
          res[L][R] = tres;
          mid[L][R] = M;
        }
      }
    }
  int64 answer = res[0][k];