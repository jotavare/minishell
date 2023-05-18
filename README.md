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
| 🟢 | `exit`          | 0        | `exit` + `\n` & exits bash                                                  |
| 🟢 | `exit `         | 0        | `exit` + `\n` & exits bash                                                  |
| 🟢 | ` exit`         | 0        | `exit` + `\n` & exits bash                                                  |
| 🟢 | `  exit  `      | 0        | `exit` + `\n` & exits bash                                                  |
| 🟢 | `"exit test"`   | 127	    | `exit test: command not found` + `\n`                                       |
| 🟢 | `"exit"`        | 0	      | `exit` & exits bash                                                  |
| 🟢 | `exit1`         | 127      | `exit1: command not found`                                                  |
| 🟢 | `exita`         | 127      | `exita: command not found`                                                  |
| 🟢 | `exit 0`        | 0        | `exit` & exits bash                                                         |
| 🟢 | `exit 1`        | 1        | `exit` & exits bash                                                         |
| 🟢 | `exit 123`      | 123	    | `exit` & exits bash                                                         |
| 🟢 | `exit 1234`     | 210      | `exit` & exits bash                                                         |
| 🟢 | `exit 1 2 3 4`  | 1	      | `exit` + `\n` + `bash: exit: too many arguments` + `\n`                     |
| 🟢 | `exit +10`      | 10	      | `exit` + `\n` & exits bash                                                  |
| 🟢 | `exit -10`      | 246	    | `exit` + `\n` & exits bash                                                  |
| 🟢 | `exit +2000`    | 208	    | `exit` + `\n` & exits bash                                                  |
| 🟢 | `exit -2000`    | 48	      | `exit` + `\n` & exits bash                                                  |
| 🟢 | `exit a`        | 2	      | `exit` + `\n` + `bash: exit: a: numeric argument required` & exits bash     |
| 🟢 | `exit abc`      | 2	      | `exit` + `\n` + `bash: exit: abc: numeric argument required` & exits bash   |
| 🟢 | `exit a b c`    | 2	      | `exit` + `\n` + `bash: exit: a: numeric argument required` & exits bash     |
| 🟢 | `exit a b c d`  | 2	      | `exit` + `\n` + `bash: exit: a: numeric argument required` & exits bash     |
| 🟢 | `exit #`        | 0	      | `exit` + `\n` & exits bash                                                  |

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
| 🟢 | `cd ~`                 | 0       | navigate to home directory                                           |
| 🟢 | `cd /`                 | 0       | navigate to root                                                                           |
| 🟢 | `cd no_file`           | 0       | `bash: cd: no_file: No such file or directory` + `\n`                                                                            |
| 🟢 | `cd1`                  | 127       | `cd1: command not found`                           |
| 🟢 | `cd 0`                 | 1       | `bash: cd: 0: No such file or directory`                                                        |
| 🟢 | `cd 1`                 | 1       | `bash: cd: 1: No such file or directory`                                                        |
| 🟢 | `cd 123`               | 1	    | `bash: cd: 123: No such file or directory`                                                        |
| 🟢 | `cd 1234`              | 1     | `bash: cd: 1234: No such file or directory`                                                         |
| 🟢 | `cd 1 2 3 4`           | 1	      | `bash: cd: too many arguments`       |
| 🟢 | `cd a`                 | 2	      | `exit` + `\n` + `bash: exit: a: numeric argument required` & closes bash    |
| 🟢 | `cd abc`               | 2	      | `exit` + `\n` + `bash: exit: abc: numeric argument required` & closes bash  |
| 🟢 | `cd a b c`             | 2	      | `exit` + `\n` + `bash: exit: a: numeric argument required` & closes bash    |
| 🟢 | `cd a b c d`           | 2	      | `exit` + `\n` + `bash: exit: a: numeric argument required` & closes bash    |
| 🟢 | `cd ../../../../../..` | 2	      | `exit` + `\n` + `bash: exit: a: numeric argument required` & closes bash    |
| 🔵 | `cd \`                 | 0       | 0                                                                           |
| 🔵 | `cd -`                 | 0       | 0                                                                           |

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

