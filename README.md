

**this project is all about interproccess communication,,
the task is to make two processes communicate to each other using signals (only SIGUSR1 & SIGUSR2)
lets call them server and clien, so the server should be able to receive messages from the client  or multiple clients.
to do so all i did is whenever i want to send a msg to the server i break that msg down to bits each bit a either  SIGUSR1 OR SIGUSR2 
for example :**
<br/>
SIGUSR1 would be 0;
SIGUSR2 would be 1;

**on the other side the server then receive each signal ,, and based on which it  convertes the signale to 1 or 0 to complete a byte (8 bits (8 signals)).
then print it.**

***but before that.<br/>***
**i used the same technique to send the number of character in the whole msg ,, that number is reveived by the server using the same method to alloc an enough space in memory to store the whole msg after receiving it bit by bit.**
<br/><br/>
*> in the bonus part the server send a msg to tell the client that msg is successfully recieved.*
<br/>
<br/><br/>
<img width="1356" alt="Screen Shot 2024-05-27 at 6 42 39 PM" src="https://github.com/4bderahim/minitalk/assets/88629357/373293b4-23f3-4bc1-880c-9c40e76dbd31">
