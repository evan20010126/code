// 1.
// var events = require('events');

// var eventEmitter = new events.EventEmitter();

// var connectHandler = function connected(){
//     console.log("connect success");
    
//     eventEmitter.emit('data_received');
// }

// eventEmitter.on('connection', connectHandler);

// eventEmitter.on('data_received', function(){
//     console.log("data");
// });

// 2. 帶有參數的事件
var events = require('events');
var eventEmitter = new events.EventEmitter();

eventEmitter.on('someEvent', function(arg1, arg2){
    console.log('listener1', arg1, arg2);
});

eventEmitter.emit('someEvent', 'apple', 'book');



