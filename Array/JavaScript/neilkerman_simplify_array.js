/**
 * Unique Elements in an array
 * 
 * This function separates out unique elements in an array and 
 * displays it once.
 * 
 * For example, 
 * 
 * Input [1,1,2,2,3,3,1,2,5,1]
 *  
 * Output [1,2,3,5]
 */


function simplify(arr){
    /**
     * The trick here is to use some method that
     * filters out duplicate values. Well fortunately
     * in javascript, we already have an object which does
     * this for us. The Set object lets you store unique 
     * values of any type, whether primitive values or 
     * object references.
     * 
     * What we need to do is, just spread the values the set
     * operator generates, and return it as an array.
     */
    return [...new Set(arr)]
}

/** 
 * Testing the function out. Comment out the line
 * below if you want to use it in some other program.
*/
console.log(simplify([1,1,2,2,3,3,1,2,5,1]))