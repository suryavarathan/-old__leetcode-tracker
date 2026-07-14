// Last updated: 7/14/2026, 3:25:06 PM
/**************************😎**************************/
const chalkReplacer=(e,l)=>{let t=0;for(let l=0;l<e.length;l++)t+=e[l];l%=t;for(let t=0;t<e.length;t++){if(l<e[t])return t;l-=e[t]}};