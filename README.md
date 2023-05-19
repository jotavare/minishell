<div align="center">
<table>
<tr><th>COLORS</th>
<tr><td>

| State | Definition |
| :---: | :--- |
| 🟢  | Working        |
| 🔴  | Not working    |
| 🔵  | Not mandatory  |

</td></tr> </table
</div>
  
<div align="center">
<table>
<tr><th>EXIT</th>
<tr><td>

| State | Built-In | `echo $?` | Output |
| :---: | :--- | :--- | :--- |
| 🔴 | `EXIT`          | 127	    | `EXIT: command not found`                                            |
| 🟢 | `exit`          | 0        | `exit` & exits bash                                                  |
| 🟢 | `exit `         | 0        | `exit` & exits bash                                                  |
| 🟢 | ` exit`         | 0        | `exit` & exits bash                                                  |
| 🟢 | `  exit  `      | 0        | `exit` & exits bash                                                  |
| 🟢 | `exit test`     | 2	      | `exit` + `bash: exit: test: numeric argument required` & exits bash  |
| 🟢 | `exit "test"`   | 2	      | `exit` + `bash: exit: test: numeric argument required` & exits bash  |
| 🟢 | `"exit test"`   | 127	    | `exit test: command not found`                                       |
| 🔴 | `"exit"`        | 0	      | `exit` & exits bash                                                  |
| 🔴 | `exit1`         | 127      | `exit1: command not found`                                           |
| 🔴 | `exita`         | 127      | `exita: command not found`                                           |
| 🟢 | `exit 0`        | 0        | `exit` & exits bash                                                  |
| 🟢 | `exit 1`        | 1        | `exit` & exits bash                                                  |
| 🟢 | `exit 123`      | 123	    | `exit` & exits bash                                                  |
| 🟢 | `exit 1234`     | 210      | `exit` & exits bash                                                  |
| 🔴 | `exit 1 2 3 4`  | 1	      | `exit` + `bash: exit: too many arguments`                            |
| 🔴 | `exit +10`      | 10	      | `exit` & exits bash                                                  |
| 🔴 | `exit -10`      | 246	    | `exit` & exits bash                                                  |
| 🔴 | `exit +2000`    | 208	    | `exit` & exits bash                                                  |
| 🔴 | `exit -2000`    | 48	      | `exit` & exits bash                                                  |
| 🔴 | `exit -2147483649`| 255    | `exit` & exits bash                                                  |
| 🔴 | `exit 2147483648` | 0      | `exit` & exits bash                                                  |
| 🔴 | `exit 00000000000000000000` | 0 | `exit` & exits bash                                             |
| 🔴 | `exit 11111111111111111111` | 2 | `exit` + `bash: exit: 11111111111111111111: numeric argument required` & exits bash |
| 🟢 | `exit exit`     | 2	      | `exit` + `bash: exit: a: numeric argument required` & exits bash     |
| 🟢 | `exit a`        | 2	      | `exit` + `bash: exit: a: numeric argument required` & exits bash     |
| 🟢 | `exit abc`      | 2	      | `exit` + `bash: exit: abc: numeric argument required` & exits bash   |
| 🔴 | `exit a b c`    | 2	      | `exit` + `bash: exit: a: numeric argument required` & exits bash     |
| 🟢 | `exit a b c d`  | 2	      | `exit` + `bash: exit: a: numeric argument required` & exits bash     |
| 🔵 | `exit #`        | n/a	    | n/a                                                                  |
| 🔵 | `exit *`        | n/a	    | n/a                                                                  |

</td></tr> </table
</div>
  
<div align="center">
<table>
<tr><th>CD</th>
<tr><td>

| State | Built-In | `echo $?` | Output |
| :---: | :--- | :--- | :--- |
| 🔴 | `CD`                   | 127	    | `CD: command not found`                                                    |
| 🟢 | `cd`                   | 0       | n/a                                                                        |
| 🟢 | `cd `                  | 0       | n/a                                                                        |
| 🟢 | ` cd`                  | 0       | n/a                                                                        |
| 🟢 | `  cd  `               | 0       | n/a                                                                        |
| 🟢 | `cd .`                 | 0       | n/a                                                                        |
| 🔴 | `cd ~`                 | 0       | navigate to home directory                                                 |
| 🟢 | `cd no_file`           | 0       | `bash: cd: no_file: No such file or directory`                             |
| 🟢 | `cd1`                  | 127     | `cd1: command not found`                                                   |
| 🟢 | `cd 0`                 | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🟢 | `cd 1`                 | 1       | `bash: cd: 1: No such file or directory`                                   |
| 🟢 | `cd 123`               | 1	      | `bash: cd: 123: No such file or directory`                                 |
| 🟢 | `cd 1234`              | 1       | `bash: cd: 1234: No such file or directory`                                |
| 🟢 | `cd 1 2 3 4`           | 1	      | `bash: cd: too many arguments`                                             |
| 🟢 | `cd cd`                | 1	      | `bash: cd: a: No such file or directory`                                   |
| 🟢 | `cd a`                 | 1	      | `bash: cd: a: No such file or directory`                                   |
| 🟢 | `cd abc`               | 1	      | `bash: cd: abc: No such file or directory`                                 |
| 🟢 | `cd a b c`             | 1	      | `bash: cd: too many arguments`                                             |
| 🟢 | `cd a b c d`           | 1	      | `bash: cd: too many arguments`                                             |
| 🔴 | `cd /`                 | 0	      | navigate to root `/$`                                                      |
| 🔴 | `cd //`                | 0	      | navigate to root `//$`                                                     |
| 🟢 | `cd ../../`            | 0	      | navigate up two directories from the current directory                     |
| 🟢 | `cd ../../../../../../`| 0	      | navigate up five directories from the current directory                    |
| 🟢 | `cd ../../...`         | 1	      | bash: cd: ../../...: No such file or directory                             |
| 🟢 | `cd .../../..`         | 1	      | bash: cd: .../../..: No such file or directory                             |
| 🟢 | `cd .../../...`        | 1	      | bash: cd: .../../...: No such file or directory                            |
| 🔵 | `cd \`                 | 1       | new prompt `>`                                                             |
| 🔵 | `cd -`                 | 0       | change to previous directory                                               |
| 🔵 | `../../`               | 126     | `bash: ../../: Is a directory`                                             |
| 🔵 | `$`                    | 127     | `$: command not found`                                                     |

</td></tr> </table
</div>
    
<div align="center">
<table>
<tr><th>CTRL</th>
<tr><td>

| State | Built-In | `echo $?` | Output |
| :---: | :--- | :--- | :--- |
| 🟢 | `Ctrl` + `C`                                   | 130  | `^C` + `\n`           |
| 🟢 | `Ctrl` + `D`                                   | 0    | `exit` & closes bash  |
| 🟢 | `Ctrl` + `\`                                   | 0    | nothing               |
| 🟢 | `write something then press` + `Ctrl` + `C`    | 0    |  n/a  |
| 🟢 | `write something then press` + `Ctrl` + `D`    | 0    |  n/a  |
| 🟢 | `write something then press` + `Ctrl` + `\`    | 0    |  n/a  |

</td></tr> </table
</div>

<div align="center">
<table>
<tr><th>ECHO</th>
<tr><td>

| State | Built-In | `echo $?` | Output |
| :---: | :--- | :--- | :--- |
| 🔴 | `ECHO`                   | 127	    | `ECHO: command not found`                                                    |
| 🟢 | `echo`                   | 0       | n/a                                                                        |
| 🟢 | `echo `                  | 0       | n/a                                                                        |
| 🟢 | ` echo`                  | 0       | n/a                                                                        |
| 🟢 | `  echo  `               | 0       | n/a                                                                        |
| 🟢 | `echo .`                 | 0       | n/a                                                                        |
| 🔴 | `echo ~`                 | 0       | navigate to home directory                                                 |
| 🔴 | `echo #`                 | 0       | navigate to home directory                                                 |
| 🟢 | `echofile`                  | 127     | `cd1: command not found`                                                   |
| 🟢 | `echo file`           | 0       | `bash: cd: no_file: No such file or directory`                             |
| 🟢 | `echo no_file`           | 0       | `bash: cd: no_file: No such file or directory`                             |
| 🟢 | `echo file     teste file   teste`                 | 1       | `bash: cd: 0: No such file or directory`                                   |
  

exec_test 'echo test tout'
exec_test 'echo test      tout'
exec_test 'echo -n test tout'
exec_test 'echo -n -n -n test tout'

echo
echo echo
eCho 
eChO
eCHO
ECHO
echo rhobebou
echo stop barking
echo "bonjour"
echo bonjour
echo 'bonjour'
echo -n bonjour
echo -nn bonjour
echo -n -n -n bonjour
echo -n -n -n bonjour
echo "-n" bonjour
echo -n"-n" bonjour
echo "-nnnn" bonjour
echo "-n -n -n"-n bonjour
echo "-n '-n'" bonjour
echo ~
echo "~"
echo '~'
echo ~123
echo 123~
echo ~/123
echo ~/123/456
echo $USER
echo "$USER"
echo "'$USER'"
echo " '$USER' "
echo text"$USER"
echo text"'$USER'" ' $USER '
echo "text"   "$USER"    "$USER"
echo '              $USER          '
echo               text "$USER"            "$USER"text
echo ''''''''''$USER''''''''''
echo """"""""$USER""""""""
echo $USER'$USER'text oui oui     oui  oui $USER oui      $USER ''
echo $USER '' $USER $USER '' $USER '' $USER -n $USER
echo ' \' ' \'
echo '\" ' " \"\""
echo \\\" \\\" \\\" \\\"\\\"\\\" \\\'\\\'\\\'
echo "$USER""$USER""$USER"
echo text"$USER"test
echo '$USER' "$USER" "text \' text"
echo '$USER'
echo $USER " "
echo "$USER""Users/$USER/file""'$USER'"'$USER'
echo "$USER$USER$USER"
echo '$USER'"$USER"'$USER'
echo '"$USER"''$USER'"""$USER"
echo " $USER  "'$PWD'
echo " $USER  \$ "'$PWD'
echo $USER=4
echo $USER=thallard
echo $USER
echo $?
echo $USER213
echo $USER$12USER$USER=4$USER12
echo $USER $123456789USER $USER123456789
echo $USER $9999USER $8888USER $7777USER
echo $USER $USER9999 $USER8888 $USER7777
echo $USER $USER9999 $USER8888 $USER7777 "$USER"
echo "$USER=12$USER"
echo "$9USER" "'$USER=12$SOMETHING'"
echo $PWD/file
echo "$PWD/file"
echo "text" "text$USER" ... "$USER"
echo $PWD
  

| 🔴 |  `echo bonjour ; |`                  |  n/a  |  n/a  |
| 🔴 |  `echo bonjour | |`                  |  n/a  |  n/a  |
| 🔴 |  `echo bonjour |;`                   |  n/a  |  n/a  |
| 🔴 |  `echo bonjour ; ls`                 |  n/a  |  n/a  |
| 🔴 |  `echo bonjour > test\ 1`            |  n/a  |  n/a  |
| 🔴 |  `echo "\s" & echo "\s"`             |  n/a  |  n/a  |
| 🔴 |  `echo >`                            |  n/a  |  n/a  |
| 🔴 |  `echo -n -n -nnnn -nnnnm`           |  n/a  |  n/a  |
| 🔴 |  `echo test > file test1`            |  n/a  |  n/a  |
| 🔴 |  `echo test > file test1`            |  n/a  |  n/a  |
| 🔴 |  `echo bonjour >>> test`             |  n/a  |  n/a  |
| 🔴 |  `echo bonjour > > out`              |  n/a  |  n/a  |
| 🔴 |  `echo 2 >> out1 > out2`             |  n/a  |  n/a  |
| 🔴 |  `echo 2 > out1 >> out2`             |  n/a  |  n/a  |
| 🔴 |  `echo "$HOME"`                      |  n/a  |  n/a  |
| 🔴 |  `echo '$HOME'`                      |  n/a  |  n/a  |
| 🔴 |  `echo $HOME`                        |  n/a  |  n/a  |
| 🔴 |  `echo hudifg d | | hugdfihd`        |  n/a  |  n/a  |
| 🔴 |  `echo`                              |  n/a  |  n/a  |
| 🔴 |  `echo simple`                       |  n/a  |  n/a  |
| 🔴 |  `echo -n simple`                    |  n/a  |  n/a  |
| 🔴 |  `echo ''`                           |  n/a  |  n/a  |
| 🔴 |  `echo ""`                           |  n/a  |  n/a  |
| 🔴 |  `echo "\"`                          |  n/a  |  n/a  |
| 🔴 |  `echo "\n \n \n"`                   |  n/a  |  n/a  |
| 🔴 |  `echo "\n \n \\n"`                  |  n/a  |  n/a  |
| 🔴 |  `echo ;;`                           |  n/a  |  n/a  |
| 🔴 |  `echo hi";" hihi`                   |  n/a  |  n/a  |
| 🔴 |  `echo hi " ; " hihi`                |  n/a  |  n/a  |
| 🔴 |  `echo $?`                           |  n/a  |  n/a  |
| 🔴 |  `echo |`                            |  n/a  |  n/a  |
| 🔴 |  `| echo`                            |  n/a  |  n/a  |
| 🔴 |  `echo > a Hello World!`             |  n/a  |  n/a  |
| 🔴 |  `> a echo Hello World!`             |  n/a  |  n/a  |
  
</td></tr> </table
</div>
