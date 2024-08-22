// hyunseo's solution

function threeSum(nums: number[]): number[][] {
  let arr: number[][] = [];
  for(let i =0; i<nums.length; i++){
      if(twoSum(nums,nums[i], i, arr).length !== 0){
          let ans: number[] = twoSum(nums,nums[i], i, arr);
          arr.push([nums[i],ans[0], ans[1]]);
          i--
      }
  }
  return arr;
};

function twoSum(nums: number[], nein: number, start: number, arr: number[][]): number[]{
  let tar: number = -nein;
  for(let i=0; i<nums.length; i++){
      let x: number = tar-nums[i];
      let y: number = nums.indexOf(x);
      let dup: boolean = false;
      if(i!==y && y!==-1 && y!== start && i!== start) {

          if(nums[i] === nums[y] && nums[y] === nein){
              for(let j=0; j<arr.length;j++){
                  if(
                      arr[j][0] === nein &&
                      arr[j][1] === nein 
                  ) return [];
              }
              return [nums[i],nums[y]];
          }
          for(let j=0; j<arr.length; j++){
              if(
                  arr[j].includes(nums[i]) && 
                  arr[j].includes(nums[y]) &&
                  arr[j].includes(nein) 
              )
              {
                  dup = true;
              }
          }
          if(!dup) return [nums[i],nums[y]];
      }
  }
  return [];
}



function BruteForceThree(nums: number[]) {
  let res: number[][] = [];
  nums.sort();
  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      for (let k = j + 1; k < nums.length; k++) {
        if (nums[i] + nums[j] + nums[k] == 0) {
          for (let x = 0; x < res.length; x++) {
            res.push([nums[i], nums[j], nums[k]]);
            if (nums[i] == res[x][0] && nums[j] == res[x][1] && nums[k] == res[x][2]) {
              res.pop();
            }
          }
        }
      }
    }
  }
}