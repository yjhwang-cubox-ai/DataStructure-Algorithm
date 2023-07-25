function power(x, n){
    // if (n==1) return x;
    if (n==0) return 1;
    return power(x, n-1) * x;
}

console.log(power(3,0))