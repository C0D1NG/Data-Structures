function findLargestElementInArray(elements) {
 return Math.max(...elements);
}

const testCase1 = [2, 3, 5, 1, 7, 9, 4];
const testCase2 = [10, 9, 8, 11, 70, 3, 1];

console.log(findLargestElementInArray(testCase1)); // 9
console.log(findLargestElementInArray(testCase2)); // 10
