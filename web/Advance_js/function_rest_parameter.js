/**
 * 測試傳入任意數量的參數進function
 */

function sum(...args){
    let sum = 0;
    for (let arg of args){
        sum += arg;
    }
    return sum;
}
let x = sum(1,2,3,4,5,6,7,9);

console.log(x);