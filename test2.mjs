function test(arr) {
    if (arr.length == 1) return arr[0];
    return test(arr.slice(0, -1)) + arr[arr.length - 1];
}

let arr = [1, 2, 3, 4, 5];
let sum = test(arr);
console.log(sum)

function power(num, p) {
    if (p == 0) return 1;
    return power(num, p - 1) * num;
}

let number = 2;
let p = 5;

console.log(power(number, p));
