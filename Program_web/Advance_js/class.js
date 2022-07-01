/**
 * JavaScript class定義方法
 * instanceof 可以判斷物件是否屬於某類別
 */


class Person{
    constructor(name){
        this.name = name;
        this.id = undefined;
    }
    static generateIDNumber(){
        return "ID";
    }
}

const person1 = new Person();
const person2 = new Person();

console.log(person1 instanceof Person); //true
console.log(person2 instanceof Person); //true
console.log(person1 == person2); //false

/**
 * 宣告為static的function表屬於整個class的function
 */
console.log(person1.id); //output: undefined
person1.name = Person.generateIDNumber(); // person1.name = person1.generateIDNumber(); Wrong!
console.log(person1.name); //output: ID

/**
 * Classical inheritance
 * 參考網址: https://www.w3schools.com/jsref/jsref_class_super.asp
 * 
 * key: extends.super
 * 
 * super語法小整理:
 * 1. super(arguments); //calls the parent constructor to get access to the parent's properties and methods(only inside the constructor)
 * 2. super.parentMethod_name(arguments); //calls a parent method
 * 
 * Note:
 * 1. 子類別的constructor()呼叫super之前，this是沒有指向的，會跑出Reference Error
 * 2. super也可以用在static method
 * 3. 若 property 被定義成不可複寫 Ex. Object.defineProperty(this, 'prop', {writable: false,}); 則super不能複寫此屬性
*/
class Player extends Person{
    constructor(name, level){
        super(name);
        this.level = level; // 如果在super()之前就呼叫this 的話，會reference error
    }
}