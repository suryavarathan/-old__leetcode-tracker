// Last updated: 7/14/2026, 3:25:48 PM
const sortSentence=function(n){return n.split(" ").sort(((n,t)=>n[n.length-1]-t[t.length-1])).map((n=>n.slice(0,n.length-1))).join(" ")};