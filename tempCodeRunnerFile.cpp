                    if(InputMatrix[b][b] == 0){
                        for(int i = b; i < n; i++){
                            if(InputMatrix[i][b]!=0){
                                index = i;
                            }
                        }
                    }
                    else{
                        for(int i = 0; i < n; i++){
                            if(b == n-1){
                            r = InputMatrix[b-1][i];
                            InputMatrix[b][i] = InputMatrix[b][i] + r;
                            IdentityMatrix[b][i] = IdentityMatrix[b][i] + r;
                            }
                            else{
                            r = InputMatrix[index][i];
                            InputMatrix[b][i] = InputMatrix[b][i] + r;
                            IdentityMatrix[b][i] = IdentityMatrix[b][i] + r;
                            }
                        }
                    }