<p align="center">
  <img src="https://github.com/jotavare/jotavare/blob/main/42/banner/new/42_minishell_banner_new.png">
</p>

<p align="center">
	<img src="https://img.shields.io/badge/status-finished-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/badge/evaluated-18%20%2F%2012%20%2F%202022-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/badge/score-0%20%2F%20100-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/github/languages/top/jotavare/minishell?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/github/last-commit/jotavare/minishell?color=%2312bab9&style=flat-square"/>
	<a href='https://www.linkedin.com/in/joaoptoliveira' target="_blank"><img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-100000?style=flat-square&logo=Linkedin&logoColor=white&labelColor=0A66C2&color=0A66C2'/></a>
	<a href='https://profile.intra.42.fr/users/jotavare' target="_blank"><img alt='42' src='https://img.shields.io/badge/Porto-100000?style=flat-square&logo=42&logoColor=white&labelColor=000000&color=000000'/></a>
</p>

<p align="center">
	<a href="#blank">blank</a> •
	<a href="#signals">signals</a> •
	<a href="#path">path</a> •
	<a href="#pwd">pwd</a> •
	<a href="#export-env-and-unset">export, env and unset</a> •
	<a href="#exit">exit</a> •
	<a href="#cd">cd</a> •
	<a href="#echo">echo</a> •
	<a href="#utilities">utilities</a>
</p>

## Before Evaluation
- [ ] Check norminette for any errors.
- [ ] No segmentation fault, bus error, double free, ...
- [ ] Must compile with -Wall, -Wextra and -Werror.
- [ ] Makefile must contain $(NAME), all, clean, fclean.
- [ ] If theres bonus, there must be a bonus rule on Makefile and bonus files must have _bonus.c(.h).
- [ ] Check for forbidden functions in your code.



| Important Commands | Description |
| :--- | :--- |
| `make -n`                         | Display the compilation information without actually compiling the code.       |
| `echo $?`                         | Display the exit status of the last executed command.                          |
| `nm -g ./minishell \| grep " U "` | Check for forbidden functions. |
| `norminette`                      | Checks the code for compliance with the coding style and guidelines.           |
| `-R CheckForbiddenSourceHeader`   | |
| `cc -g -Wall -Wextra -Werror`     | |
| `-fsanitize=address`              | |
| `-lreadline`                      | Link against the readline library.                                             |
| `ps -e` or `ps -A`                | See all processes currently running on your computer.                          |
| `ps -a`                           | While tweaking your functions, see if you're creating any dead children.       |

| Valgrind Flags                                      | Description                                      |
| :-------------------------------------------------- | :----------------------------------------------- |
| `-leak-check=full`                                  | Detailed checking for memory leaks.              |
| `--show-leak-kinds=all`                             | Display all types of memory leaks.               |
| `--track-origins=yes`                               | Tracks the origins of uninitialized values.      |
| `--verbose`                                         | Increases the level of verbosity.                |
| `--gen-suppressions=all`                            | Ignore specific known issues or false positives. |
| `--suppressions=valgrind_readline_leaks_ignore.txt` | Specifies the path to a suppression file.        |
| `--log-file=memleaks.log`                           | Sets the name of the file.                       |

```
{
    leak readline
    Memcheck:Leak
    ...
    fun:readline
}
{
    leak add_history
    Memcheck:Leak
    ...
    fun:add_history
}
```
> Note that the above suppressions file will ignore leaks related to the readline and add_history functions.

`valgrind --suppressions=your_file.txt --leak-check=full --show-leak-kinds=all ./minishell`

# COMMAND TESTS
|    | Definition                  |
| :- | :-------------------------- |
| 🟢 | Working.                    |
| 🟡 | Didn't test yet.            |
| 🟣 | Leaks or segmenation fault. |
| ⚪ | Weird behavior.             |
| 🔴 | Not working.                |
| 🔵 | Not mandatory (i think?!).  |

## BLANK
|    | Commands   |
| :- | :--------- |
| 🔴 | `<empty>`  |
| 🔴 | `<spaces>` |
| 🔴 | `../../`   |
| 🔴 | `$`        |

## SIGNALS
|    | Commands                                    |
| :- | :------------------------------------------ |
| 🔴 | `Ctrl` + `C`                                |
| 🔴 | `Ctrl` + `D`                                |
| 🔴 | `Ctrl` + `\`                                |
| 🔴 | `write something then press` + `Ctrl` + `C` |
| 🔴 | `write something then press` + `Ctrl` + `D` |
| 🔴 | `write something then press` + `Ctrl` + `\` |
| 🔴 | `cat` + `Ctrl` + `C`                        |
| 🔴 | `cat` + `Ctrl` + `D`                        |
| 🔴 | `cat` + `Ctrl` + `\`                        |
| 🔴 | `sleep 5` + `Ctrl` + `C`                    |
| 🔴 | `sleep 5` + `Ctrl` + `D`                    |
| 🔴 | `sleep 5` + `Ctrl` + `\`                    |
	
# PATH
|    | Commands           |
| :- | :----------------- |
| 🔴 | `/bin/echo`        |
| 🔴 | `/bin/grep`        |
| 🔴 | `/bin/ls`          |
| 🔴 | `/bin/ls -la`      |
| 🔴 | `/bin/cat`         |
| 🔴 | `/bin/pwd`         |
| 🔴 | `/bin/cd`          |
| 🔴 | `/bin/export`      |
| 🔴 | `/bin/env`         |
| 🔴 | `/bin/exit`        |

# PWD
|    | Commands      |
| :- | :------------ |
| 🔴 | `pwd`         |
| 🔴 | `pwd a`       |
| 🔴 | `pwd a b c d` |

# EXPORT, ENV AND UNSET
|    | Commands                         |
| :- | :------------------------------- |
| 🔴 | `ENV`                        	|
| 🔴 | `eNv`                        	|
| 🔴 | `env`                        	|
| 🔴 | ` env`                       	|
| 🔴 | `env `                       	|
| 🔴 | `  env  `                    	|
| 🔴 | `UNSET`                      	|
| 🔴 | `uNsEt`                      	|
| 🔴 | `unset`                      	|
| 🔴 | ` unset`                     	|
| 🔴 | `unset `                     	|
| 🔴 | `  unset  `                  	|
| 🔴 | `unset [variable]`           	|
| 🔴 | `unset [variable] [variable]`	|
| 🔴 | `unset [all variables]`      	|
| 🔴 | `EXPORT`                     	|
| 🔴 | `eXpOrT`                     	|
| 🔴 | `export`                     	|
| 🔴 | ` export`                    	|
| 🔴 | `export `                    	|
| 🔴 | `  export  `                 	|
| 🔴 | `export a=42`                	|
| 🔴 | `export a=24`		    		|
| 🔴 | `export b=42`                	|
| 🔴 | `export a = 42`              	|
| 🔴 | `export a=" 42 "`            	|
| 🔴 | `export a=' 42 '`            	|
| 🔴 | `export a = 42`              	|
| 🔴 | `export a` 		    			|
| 🔴 | `export a=''`           	    	|                                         
| 🔴 | `export a='"'`               	|                                   
| 🔴 | `export a='\'`               	|                                
| 🔴 | `export a='$'`               	|                                 
| 🔴 | `export a='\t'`              	|                                    
| 🔴 | `export a='''` 		 			| 
| 🔴 | `export =` 		  				|
| 🔴 | `export ==`		  				|
| 🔴 | `export a=` 		  				|
| 🔴 | `export a=42=` 		    		|
| 🔴 | `export =a=42` 		    		|
| 🔴 | `export a==42` 		    		|
| 🔴 | `export "a=42"` 		    		|
| 🔴 | `export a="42"` 		    		|
| 🔴 | `export _=42` 		    		|
| 🔴 | `export 42=42`		    		|
| 🔴 | `export a b = 42`	    		|
| 🔴 | `export a= b= 42`	    		|
| 🔴 | `export a=42 % b=42 @ c=42`  	|
| 🔴 | `export a=42 b=42 c=42`	    	|
| 🔴 | `export A=a B=b C=c D=d E=e` 	|
| 🔴 | `export F=f G=g H=h I=i J=j` 	|
| 🔴 | `export K=k L=l M=m N=n O=o` 	|
| 🔴 | `export P=p Q=q R=r S=s T=t` 	|
| 🔴 | `export U=u V=v W=w X=x Y=y Z=z` |
| 🔴 | `export _=a; echo $_a` 			|

# EXIT
|    | Commands                    |
| :- | :-------------------------- |
| 🟢 | `EXIT`                      |
| 🟢 | `eXiT`                      |
| 🟢 | `exit`                      |
| 🟢 | `exit `                     |
| 🟢 | ` exit`                     |
| 🟢 | `  exit  `                  |
| 🟢 | `exit test`                 |
| 🟢 | `exit "test"`               |
| 🟢 | `"exit test"`               |
| 🟢 | `"exit"`                    |
| 🟢 | `exit1`                     |
| 🟢 | `exita`                     |
| 🟢 | `exit exit`                 |
| 🟢 | `exit a`                    |
| 🟢 | `exit abc`                  |
| 🟢 | `exit a b c`                |
| 🟢 | `exit a b c d`              |
| 🟢 | `exit #`                    |
| 🟢 | `exit *`                    |
| 🟢 | `exit 0`                    |
| 🟢 | `exit 1`                    |
| 🟢 | `exit 123`                  |
| 🟢 | `exit 1234`                 |
| 🟢 | `exit 1 2 3 4`              |
| 🟢 | `exit +`                    |
| 🟢 | `exit -`                    |
| 🔴 | `exit +10`                  |
| 🔴 | `exit -10`                  |
| 🔴 | `exit +2000`                |
| 🔴 | `exit -2000`                |
| 🔴 | `exit +-2000`               |
| 🔴 | `exit -+2000`               |
| 🔴 | `exit ++2000`               |
| 🔴 | `exit --2000`               |
| 🔴 | `exit -2147483649`          |
| 🔴 | `exit 2147483648`           |
| 🔴 | `exit 00000000000000000000` |
| 🔴 | `exit 11111111111111111111` |
| 🔴 | `exit'42'`                  |
| 🔴 | `exit '\t42'`               |
| 🔴 | `exit '\t\f\r 42'`          |
| 🔴 | `exit '42 '`                |
| 🔴 | `exit '42\t'`               |
| 🔴 | `exit '42\r'`               |
| 🔴 | `exit '42\t\f\r '`          |
| 🔴 | `exit '42     a'`           |
| 🔴 | `exit '42\t\t\ta'`          | 


# CD  
|    | Commands                |
| :- | :---------------------- |
| 🟢 | `CD`                    |
| 🟢 | `cd`                    |
| 🟢 | `cd `                   |
| 🟢 | ` cd`                   |
| 🟢 | `  cd  `                |
| 🟢 | `cd .`                  |
| 🟢 | `cd ~`                  |
| 🟢 | `cd no_file`            |
| 🟢 | `cd1`                   |
| 🟢 | `cd 0`                  |
| 🟢 | `cd 1`                  |
| 🟢 | `cd 123`                |
| 🟢 | `cd 1234`               |
| 🟢 | `cd 1 2 3 4`            |
| 🟢 | `cd cd`                 |
| 🟢 | `cd a`                  |
| 🟢 | `cd abc`                |
| 🟢 | `cd a b c`              |
| 🟢 | `cd a b c d`            |
| 🟢 | `cd ../../`             |
| 🟢 | `cd ../../../../../../` |
| 🟢 | `cd ../../...`          |
| 🟢 | `cd .../../..`          |
| 🟢 | `cd .../../...`         |
| 🟢 | `cd \`                  |
| 🟢 | `cd /`                  |
| 🟢 | `cd //`                 |
| 🟢 | `cd ///`                |
| 🟢 | `cd -`                  |
| 🟢 | `cd $[VAR]`             |

# ECHO  
|    | Commands                                                             |
| :- | :------------------------------------------------------------------- |
| 🟢 | `ECHO`                                                               |
| 🟢 | `echO`                                                               |
| 🟢 | `ECHo`                                                               |
| 🟢 | `echo`                                                               |
| 🟢 | `echo echo`                                                          |
| 🟢 | `echo `                                                              |
| 🟢 | ` echo`                                                              |
| 🟢 | `  echo  `                                                           |
| 🟢 | `echo .`                                                             |
| 🟢 | `echo ~`                                                             |
| 🟢 | `echo echo ~`                                                        |
| 🟢 | `"echo test"`                                                        |
| 🟢 | `echo "~"`                                                           |
| 🟢 | `echo '~'`                                                           |
| 🟢 | `echo ~123`                                                          |
| 🟢 | `echo 123~`                                                          |
| 🟢 | `echo ~/123`                                                         |
| 🟢 | `echo ~/123/456`                                                     |
| 🟢 | `echo #`                                                             |
| 🟢 | `echofile`                                                           |
| 🟢 | `echo file`                                                          |
| 🟢 | `echo no_file`                                                       |
| 🟢 | `echo file test`                                                     |
| 🟢 | `echo file   test`                                                   |
| 🟢 | `echo file     test file   test`                                     |
| 🟢 | `echo a"b"c`															|
| 🟢 | `echo "a'b'c`														|
| 🟢 | `echo "test"`                                                        |
| 🟢 | `echo test`                                                          |
| 🟢 | `echo 'test'`                                                        |
| 🟢 | `echo -n`															|
| 🟢 | `echo -n -n -n -n`													|
| 🟢 | `echo -nnnnnnnnnnnnnnnnnnnnnnnn`                                     |
| 🟢 | `echo -n test -n`													|
| 🟢 | `"echo" "-n"`														|
| 🔴 | `echo -n test`                                                       |
| 🔴 | `echo -nn test`                                                      |
| 🔴 | `echo -n -n -n test`                                                 |
| 🔴 | `echo "-n" test`                                                     |
| 🔴 | `echo -n"-n" test`                                                   |
| 🔴 | `echo "-nnnn" test`                                                  |
| 🔴 | `echo "-n -n -n"-n test`                                             |
| 🔴 | `echo "-n '-n'" test `                                               |
| 🔴 | `echo -n file test`                                                  |
| 🔴 | `echo -n -n -n file test`                                            |
| 🔴 | `echo $USER`                                                         |
| 🔴 | `echo "$USER"`                                                       |
| 🔴 | `echo "'$USER'"`                                                     |
| 🔴 | `echo " '$USER' "`                                                   |
| 🔴 | `echo text"$USER"`                                                   |
| 🔴 | `echo text"'$USER'" ' $USER '`                                       |
| 🔴 | `echo "text"   "$USER"    "$USER"`                                   |
| 🔴 | `echo '              $USER          '`                               |
| 🔴 | `echo               text "$USER"            "$USER"text`             |
| 🔴 | `echo ''''''''''$USER''''''''''`                                     |
| 🔴 | `echo """"""""$USER""""""""`                                         |
| 🔴 | `echo $USER'$USER'text oui oui     oui  oui $USER oui      $USER ''` |
| 🔴 | `echo $USER '' $USER $USER '' $USER '' $USER -n $USER`               |
| 🔴 | `echo ' \' ' \'`                                                     |
| 🔴 | `echo '\" ' " \"\""`                                                 |
| 🔴 | `echo \\\" \\\" \\\" \\\"\\\"\\\" \\\'\\\'\\\'`                      |
| 🔴 | `echo "$USER""$USER""$USER"`                                         |
| 🔴 | `echo text"$USER"test`                                               |
| 🔴 | `echo '$USER' "$USER" "text \' text"`                                |
| 🔴 | `echo '$USER'`                                                       |
| 🔴 | `echo $USER " "`                                                     |
| 🔴 | `echo "$USER""Users/$USER/file""'$USER'"'$USER'`                     |
| 🔴 | `echo "$USER$USER$USER"`                                             |
| 🔴 | `echo '$USER'"$USER"'$USER'`                                         |
| 🔴 | `echo '"$USER"''$USER'"""$USER"`                                     |
| 🔴 | `echo " $USER  "'$PWD'`                                              |
| 🔴 | `echo " $USER  \$ "'$PWD'`                                           |
| 🔴 | `echo $USER=4`                                                       |
| 🔴 | `echo $USER=thallard`                                                |
| 🔴 | `echo $USER`                                                         |
| 🔴 | `echo $?`                                                            |
| 🔴 | `echo $USER213`                                                      |
| 🔴 | `echo $USER$12USER$USER=4$USER12`                                    |
| 🔴 | `echo $USER $123456789USER $USER123456789`                           |
| 🔴 | `echo $USER $9999USER $8888USER $7777USER`                           |
| 🔴 | `echo $USER $USER9999 $USER8888 $USER7777`                           |
| 🔴 | `echo $USER $USER9999 $USER8888 $USER7777 "$USER"`                   |
| 🔴 | `echo "$USER=12$USER"`                                               |
| 🔴 | `echo "$9USER" "'$USER=12$SOMETHING'"`                               |
| 🔴 | `echo $PWD/file`                                                     |
| 🔴 | `echo "$PWD/file`                                                    |
| 🔴 | `echo "text" "text$USER" ... "$USER`                                 |
| 🔴 | `echo $PW`                                                           |
| 🔴 | `echo "'"'ola'"'"`                                                   |
| 🔴 | `echo "'"' ola '"'"`                                                 |



# Utilities
### Return Values ($?)

* All Linux commands return an error code between `0` and `255`.
* The value 0 represents the value true (command success).
* Values greater than 0 represent false (command failure).
* The error code of the last command used is contained in the variable `$?`.

| $?      | Description                                                                      |
| :------ | :------------------------------------------------------------------------------- |
| `1`     | Standard for general errors, such as a division by zero.                         |
| `2`     | Improper use of built-in commands, per Bash documentation.                       |
| `126`   | The command called cannot be executed, rights problem or command not executable. |
| `127`   | Command not found, possible problem with $PATH or typing error.                  |
| `128`   | Invalid command argument.                                                        |
| `128+n` | 128 + signal number.                                                             |
| `130`   | Finished with `Ctrl` + `C` (130 = 128 + 2).                                      |
| `255`   | Exit code out of bounds, eg.: `exit -1`.                                         |

### Command Reminders
| Command   | Description                                                                                 |
| :-------- | :------------------------------------------------------------------------------------------ |
| `yes`		| Writes in an infinite loop `yes teste`.                                                     |
| `ln`		| Bind a file or directory.                                                                   |
| `chmod`	| Change file permissions `chmod 777` (4+2+1 = all permissions) `chmod 000` (no permissions). |
| `CD`		| Change directory `cd -` (last visited directory) `cd` (user directory) `cd /` (root).       |
| `clear`	| Clear the screen.                                                                           |	
| `Diff`	| Compare files line by line.                                                                 |
| `cmp`		| Write first line of difference between 2 files.                                             |
| `pc`		| Copying files.                                                                              |
| `rm`		| Delete file.                                                                                |
| `rm -rf`	| Delete the directory recursively.                                                           |
| `ls -l`	| Show the contents of the directory.                                                         |
| `exit`	| Exit current process.                                                                       |
| `grep`	| Search for strings in files `grep "printf" file`.                                           |
| `mkdir`	| Create a directory.                                                                         |
| `rmdir`	| Delete a directory.                                                                         |
| `more`	| Displays a file page by page as in a man.                                                   |
| `mv`		| Move or rename.                                                                             |
| `$PATH`	| Path to executables.                                                                        |
| `cat`		| Send the file to stdout.                                                                    |

### CHMOD
| Rights        | Number |
| :------------ | :----- |
| `r` (read)	| `4`    |
| `w` (write)	| `2`    |
| `x` (execute)	| `1`    |
	
| Rights  | Calculation | Total |
| :------ | :---------- | :---- |
| `---`   | `0+0+0`     | `0`   |
| `r--`   | `4+0+0`     | `4`   |
| `-w-`   | `0+2+0`     | `2`   |
| `--x`   | `0+0+1`     | `1`   |
| `rw-`   | `4+2+0`     | `6`   |
| `-wx`   | `0+2+1`     | `3`   |
| `x-ray` | `4+0+1`     | `5`   |
| `rwx`   | `4+2+1`     | `7`   |

### MAX/MIN
| Data Types | Qualifiers | Size (in byte) | Range |
| :- | :- | :- | :- |
| `char`	| `char` or `signed char`				| `1`            | `-128` to `127`                |
| `char`	| `unsigned char`						| `1`            | `0` to `255`                   |
| `int`		| `int` or `signed int`					| `4`            | `-2147483648` to `2147483647`  |
| `int`		| `unsigned int`						| `4`            | `0` to `4294967295`            |
| `int`		| `short int` or `short signed int`		| `2`            | `-32768` to `32767`            |
| `int`		| `unsigned short int`					| `2`            | `0` to `65535`                 |
| `int`		| `long int` or `signed long int`		| `4`            | `-2147483648` to `2147483647`  |
| `int`		| `unsigned long int`					| `4`            | `0` to `4294967295`            |
| `float`	| `float`								| `4`            | `1.1754e-38` to `3.4028e+38`   |
| `float`	| `double`								| `8`            | `2.2250e-308` to `1.7976e+308` |
| `float`	| `long double`							| `10`           | `3.4E-4932` to `3.4E+4932`     |
