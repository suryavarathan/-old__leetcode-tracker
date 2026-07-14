// Last updated: 7/14/2026, 3:21:48 PM
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var leftRightDifference = function(nums) {
  const sum = nums.reduce((a, c) => a + c);
  let pref = 0;
  for (let i = 0; i < nums.length; i++) {
    let cur = nums[i];
    nums[i] = Math.abs(pref + pref + cur - sum);
    pref += cur;
  }
  return nums;
};