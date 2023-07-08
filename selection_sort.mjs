function SelectSort(arr) {
    for (let i = 0; i < arr.length - 1; i++) {
        let minValueIndex = i;

        for (let j = i + 1; j < arr.length; j++) {
            if (arr[j] < arr[minValueIndex]) {
                minValueIndex = j;
            }
        }

        let temp = arr[i];
        arr[i] = arr[minValueIndex];
        arr[minValueIndex] = temp;
    }
}

let arr = [3, 5, 1, 2, 4];

console.log("============= 정렬 전 ===============")
console.log(arr);

SelectSort(arr);

console.log("============= 정렬 후 ===============")
console.log(arr);