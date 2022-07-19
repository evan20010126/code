var fs  = require("fs");

fs.readFile("my_file.txt", function(err, data){
    if (err) return console.log(err);
    else console.log(data.toString());
})

console.log("ending");