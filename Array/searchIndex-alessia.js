let searchInsert = function(nums, target) {
 let index =0;
 for(let i =0; i<nums.length;i++){
  if(nums[i]<target){
   index++
  }
  else{
   break;
  }
 }

 return index;
};