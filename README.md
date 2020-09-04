# <b>BSQ</b>
This was the final group project of the School21's qualifying stage. Our program should have found the largest square on the map with obstacles.




## <b>Subject</b>

### <b>The biggest square</b> :<br>

* The aim of this project is to find the biggest square on a map, avoiding obsta-cles.
* A file containing the map will be provided.  It’ll have to be passed as anargument for your program.
* The first line of the map contains information on how to read the map :
	* The number of lines on the map;
	* The "empty" character;
	* The "obstacle" character;
	* The "full" character.
  
* The map is made up of’"empty" characters’, lines and’"obstacle" characters’.
* The aim of the program is to replace’"empty" characters’by’"full"characters’in order to represent the biggest square possible.
* In the case that more than one solution exists, will choosen to represent thesquare that’s closest to the top of the map, then the one that’s most to the left.


### <b>Definition of a valid map :</b>

* All lines must have the same length.
* There’s at least one line of at least one box.
* At each end of line, there’s a line break.
* The characters on the map can only be those introduced in the first line.
* In case of an invalid map, your program should display map error on the error output followed by a line break. your program will then move on to the nextmap.

### <b>Example</b>
```
$ perl gen 10 10 4 > map_file
$ cat map_file 
10.ox
o...o..o..
......o...
.....oo...
........oo
.....o.o..
o.o..o..o.
..o.......
.o.....o.o
.......o..
.....o.o..
$ ./BSQ map_file 
o...o..o..
xxxx..o...
xxxx.oo...
xxxx....oo
xxxx.o.o..
o.o..o..o.
..o.......
.o.....o.o
.......o..
.....o.o..
```

     It is a square indeed.  Even though it might not look like itvisually.


### <b>Instructions</b>

* Your program must handle 1 to n files as parameters.
* You must respect the Norm.
* When your program receives more than one map in argument, each solution or errormust be followed by a line break.
* Should there be no passed arguments, your program must be able to read on thestandard input.
* You should have a valid Makefile that’ll compile your project.
* You may only use the following functions :exit,open,close,write,read,malloc and free.

<b>BSQ evaluation info :</b>

* We’ll start by testinglas funcionalidades(out of 10 points). Your programmust be functional.
* If you get all of those 10 points, we’ll then checkla optimizaciónof yourcode.  Two things will be evaluated here : execution speed (5 points) andmemory usage (5 points).
* Those two aspects will be checkedonlyif the first part has been validated.
* All BSQs that have passed the first part of this evaluation will be com-peting for the two optimisation tests.
* The best BSQ will be rewarded with all optimisation points.
* Other BSQs will get extra points depending on how they’re ranked : thefaster the execution, and/or the the least used memory, the more pointsit gets; the slower the execution and/or the more used memory, the fewerpoints it gets.


## <b>Make and Run</b>

To compile and run program you should clone repository and and run <b>it</b> in project deirectory:

```
$ make
$ ./BSQ 'yourmapfile'
```

for map generation:
```
$ perl gen 'num of rows' 'num of columns' 'obstruction frequency' > 'new file for map'
```

```
This program may run only in Unix environment (Linux, Mac OS). Sorry.
```

## <b>Built with</b>


* [unistd.h](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/unistd.h.html) - standard symbolic constants and types.
* [fcntl.h](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/fcntl.h.html) - file control options.
* [stdlib.h](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdlib.h.html) - standard library definitions

## <b>Authors</b>

[Nikita-prF](https://github.com/Nikita-prF)

## Additional info

The school21 has dictated some rules and restrictions for us to write code, so that some structures, functions and expressions may not be present in our code.
To get more information about all the rules of code writing, read about [Norminette](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf)




