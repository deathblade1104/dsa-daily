/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    
    const promisesArr = [promise1,promise2];
    const promisesRes = await Promise.all(promisesArr);
    
    return promisesRes[0] + promisesRes[1];
    
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */