// Last updated: 7/14/2026, 3:25:13 PM
/**************************😎**************************/
const minSpeedOnTime=(t,e)=>{let n=1,r=1e7,o=-1;if(t.length-1>e)return-1;function l(n){const r=t.length;let o=0;for(let e=0;e<r-1;e++)o+=Math.ceil(t[e]/n);return o+=t[r-1]/n,o<=e}for(;n<=r;){const t=Math.floor((r+n)/2);l(t)?(o=t,r=t-1):n=t+1}return o};