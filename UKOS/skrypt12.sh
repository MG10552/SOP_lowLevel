#! /bin/bash
function silnia ()
{
  if [ $1 -lt 0 ]
  then 
    echo "Błąd: silnia nie jest zdefiniowana dla $1"
    return 1
  else 
    if [ $1 -le 1 ]
    then 
	echo '1'
    else
	echo $((`silnia $(($1-1))`*$1))
    fi
  fi
  
return 0
}
X=`silnia $1`
echo $X

