long long int bs(long long int A){
    
    
    long long int l = 0;
    long long int r = 31624;
    
    while(r - l > 1){
        
        long long int m = (l + r) >> 1;
        
        if(((m * (m + 1)) >> 1) >= (long long int) A)
            r = m;
        else
            l = m;
    }
    
    return r;
}

long long int f(long long int x){
    return (x*(x+1)) >> 1;
}

int Solution::solve(int A) {
    if(A == 0) return 0;
    
    int A_ = abs(A);

    long long int x = bs(A_);
    
    while(f(x) % 2 != A_ % 2)
        x++;
    
    return x;
}
