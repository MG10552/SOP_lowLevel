#! /bin/bash
rm -r kat1 kat3 2>/dev/null
echo "Skrypt 1" ; echo "OK"
( mkdir kat1;cd kat1;mkdir kat2 )
pwd
{ mkdir kat3 ; cd kat3 ; mkdir kat4 ; }
pwd
cd .. ; ls kat1 kat3

