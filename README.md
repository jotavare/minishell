
<div>
<table>
<tr><th>COLORS</th>
<tr><td>

| State | Definition |
| :---: | :--- |
| 🟢  | Working                   |
| 🟡  | Didn't test yet           |
| 🔴  | Not working               |
| 🔵  | Not mandatory (i think?!) |
| n/a | Nothing                   |

</td></tr> </table
</div>

<div>
<table>
<tr><th>MISSING</th>
<tr><td>

| State | Definition |
| :---: | :--- |
| 🔴  | execve                |
| 🔴  | pipes                 |
| 🔴  | " " & ' '             |
| 🔴  | echo $? & exit        |
| 🔴  | > >> < << (redirects) |

</td></tr> </table
</div>

  
<div>
<table>
<tr><th>CTRL</th>
<tr><td>

| State | Built-In | `echo $?` |
| :---: | :--- | :--- |
| 🟢 | `Ctrl` + `C`                                   | 130  |
| 🟢 | `Ctrl` + `D`                                   | 0    |
| 🟢 | `Ctrl` + `\`                                   | 0    |
| 🟢 | `write something then press` + `Ctrl` + `C`    | 0    |
| 🟢 | `write something then press` + `Ctrl` + `D`    | 0    |
| 🟢 | `write something then press` + `Ctrl` + `\`    | 0    |

</td></tr> </table
</div>  

<div>
<table>
<tr><th>EXIT</th>
<tr><td>

| State | Built-In | `echo $?` |
| :---: | :--- | :--- |
| 🟢 | `EXIT`          | 127	    |
| 🟢 | `exit`          | 0        |
| 🟢 | `exit `         | 0        |
| 🟢 | ` exit`         | 0        |
| 🟢 | `  exit  `      | 0        |
| 🟢 | `exit test`     | 2	      |
| 🟢 | `exit "test"`   | 2	      |
| 🟢 | `"exit test"`   | 127	    |
| 🟢 | `"exit"`        | 0	      |
| 🔴 | `exit1`         | 127      |
| 🔴 | `exita`         | 127      |
| 🟢 | `exit 0`        | 0        |
| 🟢 | `exit 1`        | 1        |
| 🟢 | `exit 123`      | 123	    |
| 🟢 | `exit 1234`     | 210      |
| 🔴 | `exit 1 2 3 4`  | 1	      |
| 🔴 | `exit +10`      | 10	      |
| 🔴 | `exit -10`      | 246	    |
| 🔴 | `exit +2000`    | 208	    |
| 🔴 | `exit -2000`    | 48	      |
| 🔴 | `exit -2147483649`| 255    |
| 🔴 | `exit 2147483648` | 0      |
| 🔴 | `exit 00000000000000000000`| 0 |
| 🔴 | `exit 11111111111111111111`| 2 |
| 🟢 | `exit exit`     | 2	      |
| 🟢 | `exit a`        | 2	      |
| 🟢 | `exit abc`      | 2	      |
| 🔴 | `exit a b c`    | 2	      |
| 🟢 | `exit a b c d`  | 2	      |
| 🔵 | `exit #`        | -	      |
| 🔵 | `exit *`        | -	      |

</td></tr> </table
</div>
  
<div>
<table>
<tr><th>CD</th>
<tr><td>

| State | Built-In | `echo $?` |
| :---: | :--- | :--- |
| 🟢 | `CD`                   | 127	    |
| 🟢 | `cd`                   | 0       |
| 🟢 | `cd `                  | 0       |
| 🟢 | ` cd`                  | 0       |
| 🟢 | `  cd  `               | 0       |
| 🟢 | `cd .`                 | 0       |
| 🟢 | `cd ~`                 | 0       |
| 🟢 | `cd no_file`           | 0       |
| 🟢 | `cd1`                  | 127     |
| 🟢 | `cd 0`                 | 1       |
| 🟢 | `cd 1`                 | 1       |
| 🟢 | `cd 123`               | 1	      |
| 🟢 | `cd 1234`              | 1       |
| 🟢 | `cd 1 2 3 4`           | 1	      |
| 🟢 | `cd cd`                | 1	      |
| 🟢 | `cd a`                 | 1	      |
| 🟢 | `cd abc`               | 1	      |
| 🟢 | `cd a b c`             | 1	      |
| 🟢 | `cd a b c d`           | 1	      |
| 🟢 | `cd /`                 | 0	      |
| 🟢 | `cd ../../`            | 0	      |
| 🟢 | `cd ../../../../../../`| 0	      |
| 🟢 | `cd ../../...`         | 1	      |
| 🟢 | `cd .../../..`         | 1	      |
| 🟢 | `cd .../../...`        | 1	      |
| 🔵 | `cd \`                 | -       |
| 🔵 | `cd //`                | -	      |
| 🔵 | `cd -`                 | -       |
| 🔵 | `../../`               | -       |
| 🔵 | `$`                    | -       |

</td></tr> </table
</div>

<div>
<table>
<tr><th>ECHO</th>
<tr><td>

| State | Built-In | `echo $?` |
| :---: | :--- | :--- |
| 🟢 | `ECHO`                                                               | 127	    |
| 🟢 | `echO`                                                               | 127	    |
| 🟢 | `ECHo`                                                               | 127	    |
| 🟢 | `echo`                                                               | 0       |
| 🟢 | `echo echo`                                                          | 0       |
| 🟢 | `echo `                                                              | 0       |
| 🟢 | ` echo`                                                              | 0       |
| 🟢 | `  echo  `                                                           | 0       |
| 🟢 | `echo .`                                                             | 0       |
| 🟢 | `echo ~`                                                             | 0       |
| 🟢 | `echo echo ~`                                                        | 0       |
| 🟡 | `echo "~"`                                                           | 0       |
| 🟡 | `echo '~'`                                                           | 0       |
| 🟡 | `echo ~123`                                                          | 0       |
| 🟡 | `echo 123~`                                                          | 0       |
| 🟡 | `echo ~/123`                                                         | 0       |
| 🟡 | `echo ~/123/456`                                                     | 0       |
| 🟡 | `echo #`                                                             | 0       |
| 🟡 | `echofile`                                                           | 127     |
| 🟡 | `echo file`                                                          | 0       |
| 🟡 | `echo no_file`                                                       | 0       |
| 🟡 | `echo file test`                                                     | 1       |
| 🟡 | `echo file   test`                                                   | 1       |
| 🟡 | `echo file     test file   test`                                     | 1       |
| 🟡 | `echo "test"`                                                        | 1       |
| 🟡 | `echo test`                                                          | 1       |
| 🟡 | `echo 'test'`                                                        | 1       |
| 🟡 | `echo -n test`                                                       | 1       |
| 🟡 | `echo -nn test`                                                      | 1       |
| 🟡 | `echo -n -n -n test`                                                 | 1       |
| 🟡 | `echo -n -n -n test`                                                 | 1       |
| 🟡 | `echo "-n" test`                                                     | 1       |
| 🟡 | `echo -n"-n" test`                                                   | 1       |
| 🟡 | `echo "-nnnn" test`                                                  | 1       |
| 🟡 | `echo "-n -n -n"-n test`                                             | 1       |
| 🟡 | `echo "-n '-n'" test `                                               | 1       |
| 🟡 | `echo -n file test`                                                  | 1       |
| 🟡 | `echo -n -n -n file test`                                            | 1       |
| 🟡 | `echo $USER`                                                         | 1       |
| 🟡 | `echo "$USER"`                                                       | 1       |
| 🟡 | `echo "'$USER'"`                                                     | 1       |
| 🟡 | `echo " '$USER' "`                                                   | 1       |
| 🟡 | `echo text"$USER"`                                                   | 1       |
| 🟡 | `echo text"'$USER'" ' $USER '`                                       | 1       |
| 🟡 | `echo "text"   "$USER"    "$USER"`                                   | 1       |
| 🟡 | `echo '              $USER          '`                               | 1       |
| 🟡 | `echo               text "$USER"            "$USER"text`             | 1       |
| 🟡 | `echo ''''''''''$USER''''''''''`                                     | 1       |
| 🟡 | `echo """"""""$USER""""""""`                                         | 1       |
| 🟡 | `echo $USER'$USER'text oui oui     oui  oui $USER oui      $USER ''` | 1       |
| 🟡 | `echo $USER '' $USER $USER '' $USER '' $USER -n $USER`               | 1       |
| 🟡 | `echo ' \' ' \'`                                                     | 1       |
| 🟡 | `echo '\" ' " \"\""`                                                 | 1       |
| 🟡 | `echo \\\" \\\" \\\" \\\"\\\"\\\" \\\'\\\'\\\'`                      | 1       |
| 🟡 | `echo "$USER""$USER""$USER"`                                         | 1       |
| 🟡 | `echo text"$USER"test`                                               | 1       |
| 🟡 | `echo '$USER' "$USER" "text \' text"`                                | 1       |
| 🟡 | `echo '$USER'`                                                       | 1       |
| 🟡 | `echo $USER " "`                                                     | 1       |
| 🟡 | `echo "$USER""Users/$USER/file""'$USER'"'$USER'`                     | 1       |
| 🟡 | `echo "$USER$USER$USER"`                                             | 1       |
| 🟡 | `echo '$USER'"$USER"'$USER'`                                         | 1       |
| 🟡 | `echo '"$USER"''$USER'"""$USER"`                                     | 1       |
| 🟡 | `echo " $USER  "'$PWD'`                                              | 1       |
| 🟡 | `echo " $USER  \$ "'$PWD'`                                           | 1       |
| 🟡 | `echo $USER=4`                                                       | 1       |
| 🟡 | `echo $USER=thallard`                                                | 1       |
| 🟡 | `echo $USER`                                                         | 1       |
| 🟡 | `echo $?`                                                            | 1       |
| 🟡 | `echo $USER213`                                                      | 1       |
| 🟡 | `echo $USER$12USER$USER=4$USER12`                                    | 1       |
| 🟡 | `echo $USER $123456789USER $USER123456789`                           | 1       |
| 🟡 | `echo $USER $9999USER $8888USER $7777USER`                           | 1       |
| 🟡 | `echo $USER $USER9999 $USER8888 $USER7777`                           | 1       |
| 🟡 | `echo $USER $USER9999 $USER8888 $USER7777 "$USER"`                   | 1       |
| 🟡 | `echo "$USER=12$USER"`                                               | 1       |
| 🟡 | `echo "$9USER" "'$USER=12$SOMETHING'"`                               | 1       |
| 🟡 | `echo $PWD/file`                                                     | 1       |
| 🟡 | `echo "$PWD/file`                                                    | 1       |
| 🟡 | `echo "text" "text$USER" ... "$USER`                                 | 1       |
| 🟡 | `echo $PW`                                                           | 1       |
  
</td></tr> </table
</div>
