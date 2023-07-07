function test(arr){
    if (arr.length == 1) return arr[0];
    return test(arr.slice(0, -1)) + arr[arr.length + 1];
}

let arr = [1,2,3,4,5];
let sum = test(arr);
console.log(sum)
