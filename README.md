

this project is all about interproccess communication,,
the task is to make two processes communicate to each other using signales (only SIGUSE1 & SIGUSR2)
lets call them server and clien so the server should be able to receive messages from the client  or multiple clients.
to do so all i did is whenever i want to send a msg to the server i break that msg to bit each bit a either  SIGUSR1 OR SIGUSR2 
for example :
SIGUSR1 would be 0;
SIGUSR2 would be 1;

on the other side the server then receive each signal ,, and based on which it  convertes the signale to 1 or 0 to complete a byte (8 bits (8 signals)).
then print it.

but before that.<br/>
i used the same technique to send the number of character in the whole msg ,, that number is reveived by the server using the same method to alloc an enough space in memory to store the whole msg after receiving it bit by bit.
> is the bonus part the server send a msg to tell the client that msg is successfully recieved.
