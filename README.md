<div align="center">
<table>
<tr><th>EXIT</th>
<tr><td>

| COMMANDS        | RETURN VALUE echo $?  | OUTPUT                                                  |
| :---            | :---    | :---                                                                  |
| `exit`          | 0       | `exit` & closes bash                                                  |
| `exit `         | 0       | `exit` & closes bash                                                  |
| ` exit`         | 0       | `exit` & closes bash                                                  |
| ` exit `        | 0       | `exit` & closes bash                                                  |
| `exit1`         | 1       | `exit1: command not found` & doesn't close bash                       |
| `exit 1`        | 1       | `exit` & closes bash                                                  |
| `exit 123`      | 123	    | `exit` & closes bash                                                  |
| `exit 1234`     | 210     | `exit` & closes bash                                                  |
| `exit 1 2 3 4`  | 1	      | `exit` + `\n` + `bash: exit: too many arguments` & doesn't close bash        |
| `exit a`        | 2	      | `exit` + `\n` + `bash: exit: a: numeric argument required` & closes bash     |
| `exit abc`      | 2	      | `exit` + `\n` + `bash: exit: abc: numeric argument required` & closes bash   |
| `exit a b c`    | 2	      | `exit` + `\n` + `bash: exit: a: numeric argument required` & closes bash     |
| `exit a b c`    | 2	      | `exit` + `\n` + `bash: exit: a: numeric argument required` & closes bash     |

</td></tr> </table
</div>
  
<div align="center">
<table>
<tr><th>CD</th>
<tr><td>

| COMMANDS        | RETURN VALUE echo $?  | OUTPUT                            |
| :---            | :---                  | :---                              |
| `cd`            | 0                     | `\n`                              |
| `cd `           | 0                     | `\n`                              |
| ` cd`           | 0                     | `\n`                              |
| ` cd `          | 0                     | `\n`                              |
| `cd .`          | 0                     | `\n`                              |
| `cd ~`          | 0                     | navigate to your home directory.  |

</td></tr> </table
</div>
    
<div align="center">
<table>
<tr><th>CTRL</th>
<tr><td>

| COMMANDS      | RETURN VALUE echo $?  | OUTPUT                |
| :---          | :---                  | :---                  |
| `Ctrl` + `C`  | 130                   | `^C` + `\n`           |
| `Ctrl` + `D`  | 0                     | `exit` & closes bash  |
| `Ctrl` + `\`  | 0                     | nothing               |

</td></tr> </table
</div>

