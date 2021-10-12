#!/bin/bash
./etalon.exe $1 > 2
#./pathfinder1 $1 > 2
./pathfinder $1 > 1
diff -s 1 2
rm 1
rm 2

