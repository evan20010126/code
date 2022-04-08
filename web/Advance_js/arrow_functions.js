/**
 * ES6: arrow functions
 * 若function只有一行敘述，可以簡寫
 */

var hi1 = (x,y) => x * y; //hi1 為一個function

console.log(hi1(1,2));

var hi2 = function(x,y){ //hi2 為一個function
    return x*y;
}

console.log(hi2(1,2));

