/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    
    if(t.length !== s.length)
        return false;
    
    let sMap = new Map(), tMap = new Map();
    
    
    for(let i=0;i<s.length;i++)
        {
            if(s[i] in sMap)
                sMap[s[i]]++;
            
            else
                sMap[s[i]]=1;
            
            if(t[i] in tMap)
                tMap[t[i]]++;
            
            else
                tMap[t[i]]=1;
        }
    
    for(let ele in sMap)
        {
            if(sMap[ele] !== tMap[ele])
                return false;
        }
    
    return true;
};