// Last updated: 7/14/2026, 3:26:30 PM
/**
 * @param {number[]} nums
 * @param {number} maximumBit
 * @return {number[]}
 */
var getMaximumXor = function(nums, maximumBit) {
    let n = nums.length;
    let pre = [];
    let mask = (1 << maximumBit) - 1;  // Sets mask to the max possible value with 'maximumBit' bits (e.g., 3 bits => 0b111 = 7)
    for (let x of nums) {
        pre.push(mask ^ x);  // XOR each number in nums with the mask, effectively flipping bits to get maximum XOR
        mask ^= x;            // Update the mask to reflect cumulative XOR of seen numbers
    }
    pre.reverse();            // Reverse the list to follow the descending order requirement
    return pre;
};