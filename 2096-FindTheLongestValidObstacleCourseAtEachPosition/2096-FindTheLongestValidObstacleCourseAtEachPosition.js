// Last updated: 7/14/2026, 3:23:03 PM
/**************************😎**************************/
const longestObstacleCourseAtEachPosition=t=>{let e=[],o=[];for(let s of t){let t=_.sortedLastIndex(o,s);o[t]=s,e.push(t+1)}return e};