/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll =  function(functions) {
   
    
    return new Promise(async (resolve,reject) => {

        const sz = functions.length;
        let resolved = 0;
        const results = Array(sz);

        for(let i=0;i<sz;i++){
            functions[i]()
            .then((res) => {
                results[i] = res;
                resolved++;
                
                if(resolved === sz)
                    resolve(results);
            })
            .catch(reject);
        }    
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */