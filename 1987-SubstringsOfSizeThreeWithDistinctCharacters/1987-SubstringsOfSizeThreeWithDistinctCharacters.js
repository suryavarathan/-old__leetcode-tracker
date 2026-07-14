// Last updated: 7/14/2026, 3:25:29 PM
const countGoodSubstrings=t=>{let e=0;for(let n=0;n<t.length-2;n++){const o=t.slice(n,n+3);3===new Set(o).size&&(e+=1)}return e};