//A palindrome is a string that is spelled the same both forwards and backwards, usually without considering punctuation or word breaks. Some examples include: -"A car, a man, a maraca." -"A nut for a jar of tuna." -"madam" -"refer"

const palindromes = function (string) {
  let formatString = string.replace(/[\W_]/g, "");
  let ConvertedToLowCaseString = formatString.toLowerCase();
  let reversedString = ConvertedToLowCaseString.split("").reverse().join("");
  if (reversedString === string) {
    return true;
  } else {
    return false;
  }
};
