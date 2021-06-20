int bs(int A){
    
    
    int l = 0;
    int r = 31624;
    
    while(r - l > 1){
        
        long long int m = (l + r) >> 1;
        
        if(((m * (m + 1)) >> 1) >= (long long int) A)
            r = m;
        else
            l = m;
    }
    
    return r;
}

int f(int x){
    return (x*(x+1)) >> 1;
}

int Solution::solve(int A) {
    if(A == 0) return 0;
    
    A = abs(A);

    int x = bs(A);
    
    while(f(x) % 2 != A % 2)
        x++;
    
    return x;
}
