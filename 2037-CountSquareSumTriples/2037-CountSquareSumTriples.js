// Last updated: 7/14/2026, 3:24:23 PM
/**
 * @param {number} n
 * @return {number}
 */
var countTriples = function(n) {
    let count=0
    for (let a=1;a<=n;a++) {
        for(let b=1;b<=n;b++){
            let sum=Math.sqrt((a*a)+(b*b))
            if(Number.isInteger(sum)==true&& sum<=n){
                 count++
            }
        }
    }
    return count
    
};