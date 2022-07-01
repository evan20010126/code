/**
 * Example for javascript getter and setter
 * https://www.w3schools.com/js/js_object_accessors.asp
 * Why using getter and setter?
 * 1. It gives simpler syntax
 * 2. It allows equal syntax for properties and methods
 * 3. It can secure better data quality
 * 4. It is useful for doing things behind-the-scenes
 */

// Create an object:
const person = {
  firstName: "John",
  lastName: "Doe",
  language: "en",
  get lang() {
    return this.language.toUpperCase();
  },
  set lang(lang){
      this.language = lang;
  }
};

console.log(person.lang);

person.lang = "English";

console.log(person.lang);

//access content as a property