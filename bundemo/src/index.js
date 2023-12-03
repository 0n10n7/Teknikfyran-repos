import { Elysia } from "elysia";
console.log("Hello via Bun!");

const server = new Elysia();
server.get("/anka",() => 'hi');
server.get("/users/:user", ({params}) => `Hello ${params.user}`);
server.listen(8080);
server.get("/", () => 'balls');

console.log("Server currently running on http://localhost:8080 ...")