class EventEmitter {
    
    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    
    constructor(){
        this.mp = new Map();
    }
    
    subscribe(eventName, callback) {
        
        if(!this.mp[eventName])
            this.mp[eventName] = [];
        
        this.mp[eventName].push(callback);
        
        return {
            unsubscribe: () => {
               if(this.mp[eventName]){
                   this.mp[eventName] = this.mp[eventName].filter((curr)=>curr !== callback);
               }
                return undefined;
            }
        };
    }
    
    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
     
        return this.mp[eventName]?.map((curr) => {return curr(...args)}) || [];
    }
}