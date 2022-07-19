var http = require("http");

// Javascripts匿名函數
// createserver return的東西有listen方法可以設置port
http.createServer(function(request, response){
    response.writeHead(200, {'Content-Type': 'text/plain'});

    response.end('hello world\n');
}).listen(8888);

console.log("Server running at http://127.0.0.1:8888/")