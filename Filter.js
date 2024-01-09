let arr = ['ABC', 'BCD', 'EFZ'];

const filterByEndingWithZ = (word) => {
    if(word.endsWith('Z')) return true;
    return false;
}

function filter(arr, criteria){
    result = [];
    for(let i = 0; i < arr.length; i++) {
        if(criteria(arr[i])) result.push(arr[i]);
    }
    return result;
}

ans = filter(arr, filterByEndingWithZ);
console.log(ans);
