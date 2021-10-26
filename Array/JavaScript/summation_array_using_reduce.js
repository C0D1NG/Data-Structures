let arr = [10,1,23,22,87,56,90,1001];
let sum = arr.reduce((total, num)=>{
  return total+num;
},0);

console.log(sum);
