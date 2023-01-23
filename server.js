const { createServer } = require("http");
const { Server } = require("socket.io");

const httpServer = createServer();
const io = new Server(httpServer, {
  cors: {
    origin: "*",
  },
});

const { spawn } = require("child_process");

if (process.argv.length < 3) {
  console.log("Missing cmera index");
  return;
}

const debug = process.argv.length === 4;
console.log(`Launching ${debug ? 'with' : 'without'} debug.`)

const p = spawn("./build/stag", [process.argv[2], ...(debug ? ["t"] : [])]);

p.stdout.on("data", (data) => {
  const lines = data.toString().split("\n");
  for (const line of lines.filter((l) => !!l)) {
    const out = JSON.parse(line);
    if (debug) console.log(out);
    io.sockets.emit("points", out);
  }
});

httpServer.listen(3377);
