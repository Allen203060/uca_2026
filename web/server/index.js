// Two methods to import 
import * as http from "http";
// const http = require("http");


let value = "Hello world!";
console.log("Node.js first program", value);    

// method - createServer of the object http
// args - request and response
const server = http.createServer((req, res) => {
    res.writeHead(200, {'content-type': 'application/json'});
    // end is create response + send = res
    res.end(JSON.stringify({
        response: {
            name: "John Doe",
            description: "Hello World!",
        },
    }));
});

const hostname = "127.0.0.1";
const port = "5000";
server.listen(port, hostname);
