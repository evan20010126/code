/**
 * Example for Object construction & prototype
 * https://www.w3schools.com/js/js_object_prototypes.asp
 */

/*Object construction*/
function Person(firstName, lastName, age, eyeColor){
    // JavaScript methods are the actions that can be performed on objects.
    this.firstName = firstName;
    this.lastName = lastName;
    this.age = age;
    this.eyeColor = eyeColor;
    this.changeName = function(name){
        this.firstName = name;
    };
}

var person1 = new Person("Peter", "Wu", 17, "black");
console.log("result1:");
console.log(person1);
console.log("nationality:")
console.log(person1.nationality); //undefined 因為無此屬性
// console.log(person1.name()); //wrong! 因為無此方法
console.log("---------------------------------");

person1.changeName("EVAN");
console.log("result2:");
console.log(person1);
console.log("---------------------------------");

/*prototype uml:https://eyesofkids.gitbooks.io/javascript-start-from-es6/content/part4/prototype.html*/
/*
Prototype: 為一種讓別的物件繼承其中的屬性的物件。

Note:
1. Every function has a prototype object.
2. A function's prototype has a constructor property that references back to the function.
3. Every Object (include function) has a __proto__ property, points to it's prototype Object of inheritance.
4. Every Object has a constructor property, points to it's construction function.

JavaScript並沒有對所建立的函式，區分建構函式與一般的函式，所以只要是函式，就一定會有prototype屬性
函式以外的類型，不會有這個屬性。


Use (Adding Properties and Methods to Objects):
1. Sometimes you want to add new properties (or methods) to all existing objects of a given type.
2. Sometimes you want to add new properties (or methods) to an object constructor.
*** 原型可以很容易地動態擴充屬性與方法，可以在物件實體化後繼續擴充其中的成員， //以類別為基礎的物件導向，物件實體化後，物件和類別都是無法擴充其中成員，原型物件導向較為彈性
*** 擴充出來的屬性與方法是所有物件共享的。
*/
Person.prototype.nationality = "English"; //add property

Person.prototype.name = function(){ //add method
    return this.firstName + " " + this.lastName;
}
console.log("result3:");
console.log(person1);
console.log("nationality:");
console.log(person1.nationality);
console.log("name method:");
console.log(person1.name());
console.log("---------------------------------");

//constructor
console.log(person1.constructor);
console.log(Person.constructor);


/*Inheritance */
/**
 * Inherotamce:
 * 1. Classical inheritance
 * 2. Prototype-based inheritance 
 * //Example. Object.prototype.property = ...
 */



