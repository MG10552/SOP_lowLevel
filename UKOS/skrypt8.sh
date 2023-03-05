#! /bin/bash

echo Zmienne powloki - tablice jednowymiarowe
echo W Bashu tablice są indeksowane 
echo od 0 w sposób nie ciągły.
echo Tablica jest tworzona w momencie 
echo przypisania wartości 
echo przynajmniej jednemu elementowi tablicy:
echo 'tablica1[0]=niebieski' 
tablica1[0]=niebieski
tablica1[2]=zielony
echo 'tablica2=(01 012 0123 01234 012345)'
tablica2=(01 012 0123 01234 012345) 

echo 'tablica3=([2]=111 [5]=444 777)'
tablica3=([2]=111 [5]=444 777)
echo
echo błedne odwołania do tablic:

echo '$tablica1   : ' $tablica1
echo '$tablica1[0]: ' $tablica1[0]
echo '$tablica2[1]: ' $tablica2[1]
echo
echo prawidłowe odwolania do tablic 
echo '${tablica1[0]}: ' ${tablica1[0]}
echo '${tablica2[1]}: ' ${tablica2[1]}
echo '${tablica2[*]}: ' ${tablica2[*]}
echo '${tablica3[@]}: ' ${tablica3[@]}

echo '${tablica3[5]}: ' ${tablica3[5]}
echo '${tablica3[6]}: ' ${tablica3[6]}

echo 
echo usuniecie tablicy lub jej elementu z pamieci 
echo 'unset tablica1' 
unset tablica1
echo 'unset tablica2[3]' 
unset tablica2[3]
echo '${tablica1[*]}: ' ${tablica1[*]}
echo '${tablica2[*]}: ' ${tablica2[*]}

echo
echo 'długość elementu index w tablicy ${id_tablicy[index]}'
echo '${#tablica2[0]}' ${#tablica2[0]}
echo '${#tablica2[1]}' ${#tablica2[1]}
echo '${#tablica2[2]}' ${#tablica2[2]}
echo '${#tablica2[3]}' ${#tablica2[3]}
echo '${#tablica2[4]}' ${#tablica2[4]}
echo '${#tablica2[5]}' ${#tablica2[5]}
echo '${#tablica1}' ${#tablica1}
echo '${#tablica2}' ${#tablica2}

echo
echo 'ilość elementów w tablicy ${id_tablicy[index]}'
echo '${#tablica2[*]}' ${#tablica2[*]}
echo '${#tablica2[@]}' ${#tablica2[@]}
echo 
echo usuniecie tablicy lub jej elementu z pamieci 
echo 'unset tablica1' 
unset tablica1
echo 'unset tablica2[3]' 
unset tablica2[3]
echo '${tablica1[*]}: ' ${tablica1[*]}
echo $?
echo '${tablica2[*]}: ' ${tablica2[*]}
echo ${#tablica1}
echo $?



