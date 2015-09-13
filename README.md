# Project 1

Author: **Clark Mitchell**


This Project is incomplete and does not meet most of the requirements.
It will compile but will only prompt for word count and create an inputfile.txt from the datafiles directory.

The initial goal was create a single hashtable for the words(or groups of words) from a file,
Using a hash function that would not allow collisions but would instead rehash.
The second file which would be compared would then attempt to hash into this same table,
and all collisions would be instances of copies/plagarism.

I got out of my depth but am submitting what I have for the sake of my own sanity.


*Directory Structure:*  

* **src:** C files / source code  
* **include:** Header files  
* **documentation:** Functional Decomposition and Data Structure Description files

To run simply navigate to the project directory,
then in a shell run:

	make
	./Project1

To remove the executable and object files run:

	make clean
