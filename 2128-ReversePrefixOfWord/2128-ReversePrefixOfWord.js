// Last updated: 7/14/2026, 3:22:25 PM
const reversePrefix=(e,r)=>{const s=e.indexOf(r);return e.slice(0,s+1).split("").reverse().join("")+e.slice(s+1)};