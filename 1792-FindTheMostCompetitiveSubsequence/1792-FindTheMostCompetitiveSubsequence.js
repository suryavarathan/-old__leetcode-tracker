// Last updated: 7/14/2026, 3:29:33 PM
/**************************\U0001f60e**************************/
function mostCompetitive(nums, k) {
    let stack = [];
    for (let i = 0; i < nums.length; i++) {
        while (stack.length > 0 && nums[i] < stack[stack.length - 1] && nums.length - i - 1 >= k - stack.length) {
            stack.pop();
        }
        if (stack.length < k) {
            stack.push(nums[i])
        }
    }
    return stack;
};