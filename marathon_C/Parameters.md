# Parameters in bash-scripts
In this text, I want to share the best practices for working with git, CLI, bash commands and scripts.

## Regular expressions for working with command line parameters in bash-scripts:

Param | Description
------|--------
$0 | file name
$1 | first parameter
${!#} | last parameter
${10} | more than ninth operator numbers
$# | number of parameters
$* | all parameters as one word (example for loop step 1: for param in “$*” do  echo “$param”  ->  1 2 3 4 5)
$@ | all parameters as each other word  (example for loop step 1: for param in “$@” do  echo “$param”  ->  1)
"${@:$(($1+2))}" | rest parameters after $3
Shift  | this command shift left all parameters (before: param == $3;  after:  param == $2)

See more command line parameters and switches [here](https://habr.com/en/company/ruvds/blog/326328/)

## [Go back](../README.md)
