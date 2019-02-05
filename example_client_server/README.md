Example introductory program for multithreaded socket programming in C

cd to server file and compile using

`cc -o server server.c -lpthread`

And run the server

`./server`

In another terminal cd to client file and compile then run.

The client will send a test message to the server. The server will receive it and send it back. The client will then print what it received from the server to ensure that it received the correct message.
