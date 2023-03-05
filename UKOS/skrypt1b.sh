#! /bin/bash
rm -r kat1 kat3 2>/dev/null
echo "Skrypt 1" ; echo "OK"  
echo "Przed kodem ( ... ) `pwd`"
ps | grep skrypt

( echo "W trakcie wykonywania kodu w ( ... )" ; \
  mkdir kat1 ; cd kat1 ; mkdir kat2 ; \
  ps | grep skrypt )
#( echo 1 ; mkdir kat1 ; cd kat1 ; mkdir kat2 )
echo "Przed kodem { ... } `pwd`"
ps | grep skrypt
{ echo "W trakcie wykonywania kodu w { ... }" ; \
  mkdir kat3 ; cd kat3 ; mkdir kat4 ; \
  ps | grep skrypt ; }
#{ echo 2 ; mkdir kat3 ; cd kat3 ; mkdir kat4 ; }
echo "Po zakonczeniu { ... } `pwd`"
ps | grep skrypt
cd ..
#pwd
ls kat1 kat3
