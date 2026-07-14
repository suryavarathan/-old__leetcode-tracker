// Last updated: 7/14/2026, 3:24:00 PM
const areOccurrencesEqual=e=>{let r={};for(let t of e)r[t]=r[t]+1||1;return 1==new Set(Object.values(r)).size};