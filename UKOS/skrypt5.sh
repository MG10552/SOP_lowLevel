#! /bin/bash
echo Parametry specjalne
echo parametr \$*:
echo $*
echo "-> parametr \$* zwraca łańcuch \"\$1 \$2 \$3 ...\""
# echo '-> parametr $* zwraca łańcuch "$1 $2 $3 ..."'
echo parametr \$@:
echo $@
echo "-> parametr \$@ zwraca łańcuch \"\$1\" \"\$2\" \"\$3\" ..."
echo "parametr #:"
echo $#
echo "-> parametr \$# zwraca liczbę parametrów pozycyjnych"
echo "parametr ?:"
touch testp.dat
echo $?
rm testp.dat >/dev/null
rm nieistniejacyplik >/dev/null
echo $?
echo "-> parametr \$? zwraca 0 jeśli poprzednie polecenie 
zakonczylo sie bez bledu w przeciwnym razie kod błedu"
#wywolanie skryptu:
# ./skrypt4.sh param1 param2 param3
