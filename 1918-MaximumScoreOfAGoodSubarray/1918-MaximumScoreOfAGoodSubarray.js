// Last updated: 7/14/2026, 3:26:54 PM
/**************************😎**************************/
const maximumScore=(t,m)=>{let n=t[m],a=m,h=m,e=t[m];for(;a>0||h<t.length-1;)0===a?(h+=1,e=Math.min(e,t[h])):h===t.length-1||t[a-1]>t[h+1]?(a-=1,e=Math.min(e,t[a])):(h+=1,e=Math.min(e,t[h])),n=Math.max(n,e*(h-a+1));return n};