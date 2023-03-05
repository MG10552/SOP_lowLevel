#!/bin/bash

#ps -a
dd if='/dev/zero' of='/dev/null'& pid=$!
echo
echo "PID NOWO UTWORZONEGO PROCESU dd=$pid"
nice dd if='/dev/zero' of='/dev/null'& pid=$!
echo "PID NOWO UTWORZONEGO PROCESU nice dd=$pid"
cp '/dev/zero' '/dev/null'& pid=$!
echo "PID NOWO UTWORZONEGO PROCESU cp=$pid"
echo

ps -o "%p : %t : %a"  

echo "ZMIANA PIORTETU ISTNIEJACEGO PROCESU"
renice 5 $pid 


#pkill dd >/dev/null 
#pkill cp >/dev/null 

 

