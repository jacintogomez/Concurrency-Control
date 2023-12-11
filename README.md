# Concurrency-Control

`concurrency.cpp` shows how an unsynchronized threaded program  will print when no locks are placed around the print statements. The "proper" output of this code is below:

<img width="300" alt="Screenshot 2023-12-11 at 12 06 27 PM" src="https://github.com/jacintogomez/Concurrency-Control/assets/63368475/55bb6edc-5333-47eb-8911-674d193de5a1">


But that will not be printed as the threads will compete for the value of the num variable and access to the console. Realistically you'll see something more like 
this when running `concurrency.cpp`:

<img width="300" alt="Screenshot 2023-12-11 at 12 05 50 PM" src="https://github.com/jacintogomez/Concurrency-Control/assets/63368475/a5513850-761a-4028-ba56-de71382c6cf1">

The provided files `spinlock.cpp`, `mutex.cpp`, and `semaphore.cpp` show how the correct printing can be achieved by placing a lock around the `printmanylines()` function. 
This ensures that the blocks of numbers finish printing before allowing another thread to print its num.
