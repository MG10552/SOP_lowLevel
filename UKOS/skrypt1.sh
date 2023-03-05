#! /bin/bash
rm -r kat1 kat3 2>/dev/null
echo "Skrypt 1" ; echo "OK"  
echo "Przed kodem ( ... ) `pwd`"
ps | grep skrypt

( echo "W trakcie wykonywania kodu w ( ... )" ; \
  mkdir kat1 ; cd kat1 ; mkdir kat2 ; \
  ps | grep skrypt )

echo "Przed kodem { ... } `pwd`"
ps | grep skrypt
{ echo "W trakcie wykonywania kodu w { ... }" ; \
  mkdir kat3 ; cd kat3 ; mkdir kat4 ; \
  ps | grep skrypt ; }

echo "Po zakonczeniu { ... } `pwd`"
ps | grep skrypt
cd ..

ls kat1 kat3
