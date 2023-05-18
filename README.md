<div align="center">
<table>
<tr><th>COLORS</th>
<tr><td>

| State | Definition |
| :---: | :--- |
| 🟢  | Working        |
| 🔴  | Not working    |
| 🔵  | Not mandatory  |
| n/a | Nothing        |

</td></tr> </table
</div>
  
<div align="center">
<table>
<tr><th>EXIT</th>
<tr><td>

| State | Built-In | `echo $?` | Output |
| :---: | :--- | :--- | :--- |
| 🟢 | `exit`          | 0        | `exit` & exits bash                                                  |
| 🟢 | `exit `         | 0        | `exit` & exits bash                                                  |
| 🟢 | ` exit`         | 0        | `exit` & exits bash                                                  |
| 🟢 | `  exit  `      | 0        | `exit` & exits bash                                                  |
| 🟢 | `"exit test"`   | 127	    | `exit test: command not found`                                       |
| 🟢 | `"exit"`        | 0	      | `exit` & exits bash                                                  |
| 🟢 | `exit1`         | 127      | `exit1: command not found`                                           |
| 🟢 | `exita`         | 127      | `exita: command not found`                                           |
| 🟢 | `exit 0`        | 0        | `exit` & exits bash                                                  |
| 🟢 | `exit 1`        | 1        | `exit` & exits bash                                                  |
| 🟢 | `exit 123`      | 123	    | `exit` & exits bash                                                  |
| 🟢 | `exit 1234`     | 210      | `exit` & exits bash                                                  |
| 🟢 | `exit 1 2 3 4`  | 1	      | `exit` + `bash: exit: too many arguments`                            |
| 🟢 | `exit +10`      | 10	      | `exit` & exits bash                                                  |
| 🟢 | `exit -10`      | 246	    | `exit` & exits bash                                                  |
| 🟢 | `exit +2000`    | 208	    | `exit` & exits bash                                                  |
| 🟢 | `exit -2000`    | 48	      | `exit` & exits bash                                                  |
| 🟢 | `exit a`        | 2	      | `exit` + `bash: exit: a: numeric argument required` & exits bash     |
| 🟢 | `exit abc`      | 2	      | `exit` + `bash: exit: abc: numeric argument required` & exits bash   |
| 🟢 | `exit a b c`    | 2	      | `exit` + `bash: exit: a: numeric argument required` & exits bash     |
| 🟢 | `exit a b c d`  | 2	      | `exit` + `bash: exit: a: numeric argument required` & exits bash     |
| 🟢 | `exit #`        | 0	      | `exit` & exits bash                                                  |

</td></tr> </table
</div>
  
<div align="center">
<table>
<tr><th>CD</th>
<tr><td>

| State | Built-In | `echo $?` | Output |
| :---: | :--- | :--- | :--- |
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

</td></tr> </table
</div>
    
<div align="center">
<table>
<tr><th>CTRL</th>
<tr><td>

| State | Built-In | `echo $?` | Output |
| :---: | :--- | :--- | :--- |
| 🟢 | `Ctrl` + `C`  | 130  | `^C` + `\n`           |
| 🟢 | `Ctrl` + `D`  | 0    | `exit` & closes bash  |
| 🟢 | `Ctrl` + `\`  | 0    | nothing               |

</td></tr> </table
</div>

../../
$
# write something the press ctrl+c
 # write something then press ctrl+d
 # write something then press ctrl+\

  
<div align="center">
<table>
<tr><th>ECHO</th>
<tr><td>

| State | Built-In | `echo $?` | Output |
| :---: | :--- | :--- | :--- |
| 🟢 | `exit`          | 0        | `exit` & exits bash                                                  |

echo bonjour ; |
echo bonjour | |
echo bonjour |;
echo bonjour ; ls
echo bonjour > test\ 1
echo "\s" & echo "\s"
echo >
echo -n -n -nnnn -nnnnm
echo test > file test1
echo test > file test1
echo bonjour >>> test
 echo bonjour > > out
 echo 2 >> out1 > out2
 echo 2 > out1 >> out2
  echo "$HOME"
 echo '$HOME'
   echo $HOME
  echo hudifg d | | hugdfihd
 echo
 echo simple
 echo -n simple
 echo ''
 echo ""
 echo "\"
 echo "\n \n \n"
 echo "\n \n \\n"
 echo ;;
 echo hi";" hihi
 echo hi " ; " hihi
 echo $?
  echo |
 | echo
 echo > a Hello World!
 > a echo Hello World!
  
</td></tr> </table
</div>
