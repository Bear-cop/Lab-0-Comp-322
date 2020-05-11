05/09/2020
added files and such - in spiritd.c for what it seems I need a signal handler and have a normal main method
- in mole.c, I just need to create a new file with correct pathing to it.

05/10/2020

in spiritd.c, I got help from my friend and gave me a basic layout of what I should use such as rlimit and having a opening and closing files and mapping it to dev null. At this point im finishing up the signalHandler method, then I will start on the main method soon.

05/11/2020

The end. I finished the signalHandler and inserted it to the main method where signals are caught. The main basically has the pathing of lab6.log. Makefile and Mole.c will be kept the same no change seems to be applied. This doesnt work perfectly but I'm behind so it does what its basic thing supposed to do.
