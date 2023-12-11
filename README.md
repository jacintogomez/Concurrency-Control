# Concurrency-Control

`concurrency.cpp` shows how an unsynchronized threaded program  will print when no locks are placed around the print statements. The "proper" output of this code is below:

0
0
0
 1
 1
 1
  2
  2
  2
   3
   3
   3
    4
    4
    4

But that will not be printed as the threads will compete for the value of the num variable and access to the console. Realistically you'll see something more like 
this when running `concurrency.cpp`:

0 1  2

   3
   3
   3
  2
  2

0
0
 1
 1
    4
    4
    4

The provided files `spinlock.cpp`, `mutex.cpp`, and `semaphore.cpp` show how the correct printing can be achieved by placing a lock around the `printmanylines()` function. 
This ensures that the blocks of numbers finish printing before allowing another thread to print its num.
