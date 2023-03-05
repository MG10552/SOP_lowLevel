//-----------------------------------------------ZAD_1-------------------------------------------------------

#!/bin/bash

function fib() {

	if [ $1 -le 0 ]; then
		echo 0
	elif [ $1 -eq 1 ]; then
		echo 1
	else
		echo $[ `fib $[$1-2]`+`fib $[$1-1]` ];
	fi
}

for i in `seq 1 $1`; do
	echo -n "Dla elementu $i: ";
	fib $i
done

//-----------------------------------------------ZAD_2-------------------------------------------------------

#!/bin/bash

for plik in $(ls)
do
	case $plik in
		*.txt ) mv $plik /tmp ;;
		*.png ) convert $plik "$plik.jpeg" ;;
		*.c ) gcc $plik -o "$plik.out" ;;
		* ) echo "Nie wiem co zrobic z plikiem $plik" ;;
	esac
done

//-----------------------------------------------ZAD_3-------------------------------------------------------
???
//-----------------------------------------------ZAD_4-------------------------------------------------------

#!/bin/bash

for var in "$@"
do
	echo ${var:1:4}
done

//-----------------------------------------------ZAD_5-------------------------------------------------------
???
//-----------------------------------------------ZAD_6-------------------------------------------------------

#!/bin/bash

getent passwd | awk -F ":" '{ print $1 " " $6}'
cat /etc/passwd | awk -F ":" '{ print $1 " " $6}'
awk -F ":" '{ print $1 " " $6}' /etc/passwd

//-----------------------------------------------ZAD_7-------------------------------------------------------

#!/bin/bash

# tak:
awk -F ":" '$1~/...+/{ print $1 " " $6}' /etc/passwd
# albo tak:
awk -F ":" '$1~/.{3,}/{ print $1 " " $6}' /etc/passwd

//-----------------------------------------------ZAD_8-------------------------------------------------------

#!/bin/bash

echo "<html><body><table>" > pliczek.html
getent passwd |awk -F ":" '{print "<tr><td>" $1 "</td><td>" $6 "</td><td>" $7 "</td></tr>"}' >> pliczek.html
	
echo "</table></body></html>" >> pliczek.html
