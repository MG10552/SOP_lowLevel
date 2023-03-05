#! /bin/bash
function minimum ()
{
  if [ $# -eq 0 ]
  then 
    echo 'Błąd: liczba parametrow wywolania skryptu <1!'
    return 1
  fi
  MIN=$1
  for I
  do
    if [ $MIN -gt $I ]
    then
	MIN=$I
    fi
  done
  echo $MIN
  return 0
}
X=`minimum $*`
echo $X
minimum 2 5 8 -4

