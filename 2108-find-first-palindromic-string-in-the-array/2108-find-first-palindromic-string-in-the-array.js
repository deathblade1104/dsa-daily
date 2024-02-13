/**
 * @param {string[]} words
 * @return {string}
 */

const isPalindrome = (word) => {
    
    const wordArr = word.split("");
    let i=0, j = wordArr.length - 1;
    
    while(i<j){
        
        if(wordArr[i]!== wordArr[j])
            return false;
        
        i++;
        j--;
    }
    
    return true;
}

const firstPalindrome = function(words) {
    
    
    for(let i=0;i<words.length;i++){
        
        if(isPalindrome(words[i]))
            return words[i];
    }
    
    return "";
};