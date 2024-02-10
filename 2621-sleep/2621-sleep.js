/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    
    await new Promise((resolve,reject) =>{
        setTimeout(resolve, millis);
    })
    
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */