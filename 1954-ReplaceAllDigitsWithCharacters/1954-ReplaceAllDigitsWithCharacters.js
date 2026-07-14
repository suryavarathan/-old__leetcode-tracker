// Last updated: 7/14/2026, 3:26:10 PM
const replaceDigits=r=>Array.from({length:r.length},((e,o)=>o%2?String.fromCharCode(r.charCodeAt(o-1)+ +r[o]):r[o])).join("");