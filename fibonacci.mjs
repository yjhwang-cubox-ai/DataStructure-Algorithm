function fibonacci1(n) {
    if (n == 1 || n == 0) return n;
    return fibonacci1(n - 2) + fibonacci1(n - 1);
}

function fibonacci2(n, memo) {
    if (n == 1 || n == 0) return n;

    if (memo[n] == null) {
        memo[n] = fibonacci2(n - 2, memo) + fibonacci2(n - 1, memo);
    }

    return memo[n];
}

function fibonacci3(n) {
    if (n <= 1) return n;

    let table = [0, 1];
    for (let i = 2; i <= n; i++) {
        table[i] = table[i - 2] + table[i - 1];
    }

    return table[n]
}


let start = new Date();
console.log(fibonacci1(40));
let end = new Date();
console.log(`fibonacci1 걸린시간 ${end - start}ms`);

start = new Date();
console.log(fibonacci2(40, {}));
end = new Date();
console.log(`fibonacci1 걸린시간 ${end - start}ms`);

start = new Date();
console.log(fibonacci3(40, {}));
end = new Date();
console.log(`fibonacci1 걸린시간 ${end - start}ms`);