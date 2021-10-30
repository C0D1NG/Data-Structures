/**
 * Function to calculate difference between sum of two arrays
 * 
 * Input: [1,2,3,2,1,2], [1,2,3]
 * 
 * Output : 5
 */

function sumAll(arr1, arr2){
    /**
     * The trick here is to use the reduce method
     * I've used reduce to get two values at once and return the sum
     */
    return arr1.reduce((a,b)=>a+b) - arr2.reduce((a,b)=>a+b)
}

/** 
 * Testing the function out. Comment out the line
 * below if you want to use it in some other program.
*/
console.log(sumAll([1,2,3,2,1,2], [1,2,3]))