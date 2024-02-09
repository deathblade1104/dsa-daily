/**
 * @return {Function}
 */
// var createHelloWorld = function() {
    
//     return function(...args) {
        
//         console.log("Hello World");
        
//     }
// };


const createHelloWorld = () =>{
    
    return () => { return "Hello World"};
}
/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */