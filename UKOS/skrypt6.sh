#! /bin/bash

echo Zmienne powloki
echo "deklaracja zmiennej: dowolny nazwa (litery, cyfry i znak podkreślenia)"
echo "użycie zmiennej: \$nazwa_zmiennej"
echo ZM1=tekst1:
ZM1=tekst1
echo $ZM1
echo ZM2=5:
ZM2=5
echo $ZM2
echo ZM3=ZM2:
ZM3=ZM2
echo $ZM3
echo "ZM4=\$ZM2:"
ZM4=$ZM2
echo $ZM4

CZAS=`date +%H:%M`
echo $CZAS
GODZ=`date +%H`
echo $GODZ
NGODZ=$GODZ+1
echo $NGODZ
CZAS2=`date +%y-%m-%d' '%H:%M`
echo $CZAS2 
CZAS3=`date '+%y-%m-%d %H:%M'`
echo $CZAS3 
CZAS4= `date "+%y-%m-%d %H:%M"`
echo $CZAS4 

echo błędna składnia GODZ= \`date +%H\`
echo prawidłowa składnia GODZ=\`date +%H\`


