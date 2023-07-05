function strLength(arr){
    if (arr[0] == null) return 0;
    return strLength(arr.slice(0,-1)) + 1;
}

let arr = "abcde";
let len = strLength(arr);
console.log(len);