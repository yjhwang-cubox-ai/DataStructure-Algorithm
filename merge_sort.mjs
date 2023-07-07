function MergeSort(arr, leftIndex, rightIndex) {
    if (leftIndex < rightIndex) {
        let midIndex = parseInt((leftIndex + rightIndex) / 2);
        MergeSort(arr, leftIndex, midIndex);
        MergeSort(arr, midIndex + 1, rightIndex);
        Merge(arr, leftIndex, midIndex, rightIndex);
    }
}

function Merge(arr, leftIndex, midIndex, rightIndex){
    let leftAreaIndex = leftIndex;
    let RightAreaIndex = midIndex + 1;

    let tempArr = [];
    tempArr.length = rightIndex + 1;
    tempArr.fill(0, 0, rightIndex + 1);

    let tempArrIndex = leftIndex;
    while(leftAreaIndex <= midIndex && RightAreaIndex <= rightIndex){
        if (arr[leftAreaIndex] <= arr[RightAreaIndex]){
            tempArr[tempArrIndex] = arr[leftAreaIndex ++];
            // leftAreaIndex ++;
        }else{
            tempArr[tempArrIndex] = arr[RightAreaIndex++];
            // RightAreaIndex ++;
        }
        tempArrIndex++;
    }

    if (leftAreaIndex > midIndex){
        for (let i = RightAreaIndex; i <= rightIndex; i++){
            tempArr[tempArrIndex++] = arr[i];            
        }
    }else{
        for(let i = leftAreaIndex; i <= midIndex; i++){
            tempArr[tempArrIndex++] = arr[i];
        }
    }

    for(let i = leftIndex; i <= rightIndex; i++){
        arr[i] = tempArr[i];
    }
}

let arr = [3,5,2,4,1,7,8,6];

console.log("============ 정렬 전 ============");
console.log(arr);
MergeSort(arr, 0, arr.length-1);
console.log("============ 정렬 전 ============");
console.log(arr);