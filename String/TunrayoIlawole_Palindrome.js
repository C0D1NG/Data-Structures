// A palindrom is a word or sentence that is spelled the same way forward and backwards, ignoring case, punctuation and spacing.

const PALINDROME = (str) => {
    // convert string to lowercase and remove all punctuation and symbols
    str = str.toLowerCase().replace(/[-!@#/$%^&_*(),.?":{}|<>]/g, '');
    // remove all white-spaces
    str = str.replace(/\s/g, '');
    // convert the string to an array so it can be reversed
    const arr = str.split('');

    if (str === arr.reverse().join('')) {
        return true;
    }
    else {
        return false;
    }
}

console.log(PALINDROME("race car"));