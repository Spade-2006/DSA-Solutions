function findMinMax(arr) {
    const n = arr.length;
    let mini, maxi, i;

    // Initialize min and max
    if (n % 2 === 1) {
        mini = maxi = arr[0];
        i = 1;
    } else {
        if (arr[0] < arr[1]) {
            mini = arr[0];
            maxi = arr[1];
        } else {
            mini = arr[1];
            maxi = arr[0];
        }
        i = 2;
    }

    // Process elements in pairs
    while (i < n - 1) {
        if (arr[i] < arr[i + 1]) {
            mini = Math.min(mini, arr[i]);
            maxi = Math.max(maxi, arr[i + 1]);
        } else {
            mini = Math.min(mini, arr[i + 1]);
            maxi = Math.max(maxi, arr[i]);
        }
        i += 2;
    }

    return [mini, maxi];
}

const arr = [3, 5, 4, 1, 9];
const result = findMinMax(arr);
console.log(result[0], result[1]);