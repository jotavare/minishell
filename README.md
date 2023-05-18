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
| 🟢 | `exit a`        | 2	      | `exit` + `bash: exit: a: numeric argument required` & exits bash     |
| 🟢 | `exit abc`      | 2	      | `exit` + `bash: exit: abc: numeric argument required` & exits bash   |
| 🔴 | `exit a b c`    | 2	      | `exit` + `bash: exit: a: numeric argument required` & exits bash     |
| 🟢 | `exit a b c d`  | 2	      | `exit` + `bash: exit: a: numeric argument required` & exits bash     |
| 🔴 | `exit #`        | 0	      | `exit` & exits bash                                                  |

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
| 🔵 | ../../                 | n/a     | n/a                                                                        |
| 🔵 | $                      | n/a     | n/a                                                                        |
  
</td></tr> </table
</div>
    
<div align="center">
<table>
<tr><th>CTRL</th>
<tr><td>

| State | Built-In | `echo $?` | Output |
| :---: | :--- | :--- | :--- |
| 🟢 | `Ctrl` + `C`                             | 130  | `^C` + `\n`           |
| 🟢 | `Ctrl` + `D`                             | 0    | `exit` & closes bash  |
| 🟢 | `Ctrl` + `\`                             | 0    | nothing               |
| 🟢 | `# write something then press ctrl+c`    |  0  |  n/a  |
| 🟢 | `# write something then press ctrl+d`    |  0  |  n/a  |
| 🟢 | `# write something then press ctrl+\`    |  0  |  n/a  |

</td></tr> </table
</div>

<div align="center">
<table>
<tr><th>ECHO</th>
<tr><td>

| State | Built-In | `echo $?` | Output |
| :---: | :--- | :--- | :--- |
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
