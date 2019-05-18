# simple-tcp-server
As an assignment for computer networks, we had to create a TCP server in a low level language. This is what I've made.

<p align="center">
  <img src="https://i.imgur.com/PAujqx8.png" alt="The simple CLI of the server" height="300px" />
</p>

## Installation
If you want to install this server to continue the development of it or to use it, you can use the Makefile.

```bash
git clone https://github.com/Bowero/simple-tcp-server.git
cd simple-tcp-server
make install
```

## Usage
Using the application is very easy. You can run the server with `./simple-tcp-server`. Of course, you can also pass arguments to the application.
Run `./simple-tcp-server -h` to see all the options. As per now, there are not a lot:

```
-p / --port        Which port to use to open the server on
                   (default: 3490)
-b / --backlog     How many connections to accept in queue
                   (default: 10)
-h / --help        Show this information
-v / --version     Show the current version of simple-tcp-server
```

Then you can connect to it. The easiest way is to use telnet.

```bash
telnet ip-address port
```

If you are testing locally, that results in the following:

```bash
telnet localhost 3490
```

## Contributing
If you want to request a feature, you can create an issue of course. You can also build it yourself and do a pull request.
Undocumented code won't be accepted however.
