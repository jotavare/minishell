<div>
<table>
<tr><th>COLORS</th>
<tr><td>

| State | Definition |
| :---: | :--- |
| 🟢  | Working                   |
| 🔴  | Not working               |
| 🔵  | Not mandatory (i think?!) |
| n/a | Nothing                   |

</td></tr> </table
</div>

<div>
<table>
<tr><th>CTRL</th>
<tr><td>

| State | Built-In | `echo $?` | Output |
| :---: | :--- | :--- | :--- |
| 🟢 | `Ctrl` + `C`                                   | 130  | `^C` + `\n`           |
| 🟢 | `Ctrl` + `D`                                   | 0    | `exit` & closes bash  |
| 🟢 | `Ctrl` + `\`                                   | 0    | n/a                   |
| 🟢 | `write something then press` + `Ctrl` + `C`    | 0    | n/a                   |
| 🟢 | `write something then press` + `Ctrl` + `D`    | 0    | n/a                   |
| 🟢 | `write something then press` + `Ctrl` + `\`    | 0    | n/a                   |

</td></tr> </table
</div>  

<div>
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
| 🟢 | `"exit"`        | 0	      | `exit` & exits bash                                                  |
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
| 🔴 | `exit 00000000000000000000`| 0 | `exit` & exits bash                                              |
| 🔴 | `exit 11111111111111111111`| 2 | `exit` + `bash: exit: 11111111111111111111: numeric argument required` & exits bash |
| 🟢 | `exit exit`     | 2	      | `exit` + `bash: exit: a: numeric argument required` & exits bash     |
| 🟢 | `exit a`        | 2	      | `exit` + `bash: exit: a: numeric argument required` & exits bash     |
| 🟢 | `exit abc`      | 2	      | `exit` + `bash: exit: abc: numeric argument required` & exits bash   |
| 🔴 | `exit a b c`    | 2	      | `exit` + `bash: exit: a: numeric argument required` & exits bash     |
| 🟢 | `exit a b c d`  | 2	      | `exit` + `bash: exit: a: numeric argument required` & exits bash     |
| 🔵 | `exit #`        | -	      | -                                                                  |
| 🔵 | `exit *`        | -	      | -                                                                  |

</td></tr> </table
</div>
  
<div>
<table>
<tr><th>CD</th>
<tr><td>

| State | Built-In | `echo $?` | Output |
| :---: | :--- | :--- | :--- |
| 🟢 | `CD`                   | 127	    | `CD: command not found`                                                    |
| 🟢 | `cd`                   | 0       | n/a                                                                        |
| 🟢 | `cd `                  | 0       | n/a                                                                        |
| 🟢 | ` cd`                  | 0       | n/a                                                                        |
| 🟢 | `  cd  `               | 0       | n/a                                                                        |
| 🟢 | `cd .`                 | 0       | n/a                                                                        |
| 🟢 | `cd ~`                 | 0       | navigate to home directory                                                 |
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
| 🟢 | `cd /`                 | 0	      | navigate to root `/$`                                                      |
| 🟢 | `cd ../../`            | 0	      | navigate up two directories from the current directory                     |
| 🟢 | `cd ../../../../../../`| 0	      | navigate up five directories from the current directory                    |
| 🟢 | `cd ../../...`         | 1	      | bash: cd: ../../...: No such file or directory                             |
| 🟢 | `cd .../../..`         | 1	      | bash: cd: .../../..: No such file or directory                             |
| 🟢 | `cd .../../...`        | 1	      | bash: cd: .../../...: No such file or directory                            |
| 🔵 | `cd \`                 | -       | -                                                                          |
| 🔵 | `cd //`                | -	      | -                                                                          |
| 🔵 | `cd -`                 | -       | -                                                                          |
| 🔵 | `../../`               | -       | -                                                                          |
| 🔵 | `$`                    | -       | -                                                                          |

</td></tr> </table
</div>

<div>
<table>
<tr><th>ECHO</th>
<tr><td>

| State | Built-In | `echo $?` | Output |
| :---: | :--- | :--- | :--- |
| 🟢 | `ECHO`                                                               | 127	    | `ECHO: command not found`                                                  |
| 🟢 | `echO`                                                               | 127	    | `ECHO: command not found`                                                  |
| 🟢 | `ECHo`                                                               | 127	    | `ECHO: command not found`                                                  |
| 🟢 | `echo`                                                               | 0       | `\n`                                                                       |
| 🟢 | `echo echo`                                                          | 0       | `echo`                                                                     |
| 🟢 | `echo `                                                              | 0       | n/a                                                                        |
| 🟢 | ` echo`                                                              | 0       | n/a                                                                        |
| 🟢 | `  echo  `                                                           | 0       | n/a                                                                        |
| 🟢 | `echo .`                                                             | 0       | `.`                                                                        |
| 🟢 | `echo ~`                                                             | 0       | print home directory                                                       |
| 🟢 | `echo echo ~`                                                        | 0       | `echo` + print home directory                                              |
| 🟢 | `echo "~"`                                                           | 0       | `~`                                                                        |
| 🟢 | `echo '~'`                                                           | 0       | `~`                                                                        |
| 🔴 | `echo ~123`                                                          | 0       | navigate to home directory                                                 |
| 🔴 | `echo 123~`                                                          | 0       | navigate to home directory                                                 |
| 🔴 | `echo ~/123`                                                         | 0       | navigate to home directory                                                 |
| 🔴 | `echo ~/123/456`                                                     | 0       | navigate to home directory                                                 |
| 🔴 | `echo #`                                                             | 0       | navigate to home directory                                                 |
| 🔴 | `echofile`                                                           | 127     | `cd1: command not found`                                                   |
| 🔴 | `echo file`                                                          | 0       | `bash: cd: no_file: No such file or directory`                             |
| 🔴 | `echo no_file`                                                       | 0       | `bash: cd: no_file: No such file or directory`                             |
| 🔴 | `echo file test`                                                     | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo file   test`                                                   | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo file     test file   test`                                     | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo "test"`                                                        | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo test`                                                          | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo 'test'`                                                        | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo -n test`                                                       | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo -nn test`                                                      | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo -n -n -n test`                                                 | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo -n -n -n test`                                                 | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo "-n" test`                                                     | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo -n"-n" test`                                                   | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo "-nnnn" test`                                                  | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo "-n -n -n"-n test`                                             | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo "-n '-n'" test `                                               | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo -n file test`                                                  | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo -n -n -n file test`                                            | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo $USER`                                                         | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo "$USER"`                                                       | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo "'$USER'"`                                                     | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo " '$USER' "`                                                   | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo text"$USER"`                                                   | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo text"'$USER'" ' $USER '`                                       | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo "text"   "$USER"    "$USER"`                                   | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo '              $USER          '`                               | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo               text "$USER"            "$USER"text`             | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo ''''''''''$USER''''''''''`                                     | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo """"""""$USER""""""""`                                         | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo $USER'$USER'text oui oui     oui  oui $USER oui      $USER ''` | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo $USER '' $USER $USER '' $USER '' $USER -n $USER`               | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo ' \' ' \'`                                                     | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo '\" ' " \"\""`                                                 | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo \\\" \\\" \\\" \\\"\\\"\\\" \\\'\\\'\\\'`                      | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo "$USER""$USER""$USER"`                                         | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo text"$USER"test`                                               | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo '$USER' "$USER" "text \' text"`                                | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo '$USER'`                                                       | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo $USER " "`                                                     | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo "$USER""Users/$USER/file""'$USER'"'$USER'`                     | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo "$USER$USER$USER"`                                             | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo '$USER'"$USER"'$USER'`                                         | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo '"$USER"''$USER'"""$USER"`                                     | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo " $USER  "'$PWD'`                                              | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo " $USER  \$ "'$PWD'`                                           | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo $USER=4`                                                       | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo $USER=thallard`                                                | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo $USER`                                                         | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo $?`                                                            | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo $USER213`                                                      | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo $USER$12USER$USER=4$USER12`                                    | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo $USER $123456789USER $USER123456789`                           | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo $USER $9999USER $8888USER $7777USER`                           | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo $USER $USER9999 $USER8888 $USER7777`                           | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo $USER $USER9999 $USER8888 $USER7777 "$USER"`                   | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo "$USER=12$USER"`                                               | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo "$9USER" "'$USER=12$SOMETHING'"`                               | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo $PWD/file`                                                     | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo "$PWD/file`                                                    | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo "text" "text$USER" ... "$USER`                                 | 1       | `bash: cd: 0: No such file or directory`                                   |
| 🔴 | `echo $PW`                                                           | 1       | `bash: cd: 0: No such file or directory`                                   |
  
</td></tr> </table
</div>
