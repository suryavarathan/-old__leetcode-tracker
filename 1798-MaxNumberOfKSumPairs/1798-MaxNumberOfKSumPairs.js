// Last updated: 7/14/2026, 3:29:27 PM
const maxOperations=(t,e)=>{t.sort((t,e)=>t-e);let r=0,n=0,o=t.length-1;for(;n<o;){let l=t[n]+t[o];l===e?(n++,o--,r++):l>e?o--:n++}return r};