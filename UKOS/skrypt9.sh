#!/bin/bash
# Polecenia testujące 
#  1) test wyrażenie
#  2) [ wyrażenie ]

# dla liczb calkowitych
# a -eq b  => a=b
# a -ne b  => a<>b
# a -le b  => a<=b
# a -lt b  => a<b
# a -ge b  => a>=b
# a -gt b  => a>b

# dla łańcuchów
# -z lan   => łańcuch lan ma długość 0
# -n lan   => łańcuch lan ma długość <> 0 
# lan1 == lan2    => łańcuchy są identyczne
# lan1 != lan2    => łańcuchy są różne

# dla plików
# -e plik 	=> plik istnieje
# -d plik 	=> plik istnieje i jest katalogiem
# -r plik 	=> -||- i jest odczytywalny
# -w plik 	=> -||- i jest zapisywalny
# -x plik 	=> -||- i jest uruchamialny / wykonywalny
# plik1 -nt plik2 	=> plik1 jest nowszy od plik2
# plik1 -ot plik2 	=> plik1 jest starszy od plik2

# logiczne wyrażenia testowe
# ( wyrażenie ) 	=> sprawdzenie 
#			prawdziwości wyrażenia
# !wyrazenie		=> wyrażenie fałszywe
# wyr1 -a wyr2 		=> AND - oba wyrażenia są prawdziwe
# wyr1 -o wyr2 		=> OR - jedno lub drugie wyrażenie jest prawdziwe



# instrukacja warunkowa if

# if polecenie_testujące
# then
# 	polecenie_do_wykonania
# fi

echo START
if [ $# -eq 2 -a "$1" == r ]
then 
    echo "Skrypt uruchomiono z dwoma parametrami,"
    echo "a pierwszy z nich to r (1)"
else
    echo "Skrypt uruchomiono z $# parametrami,"
    echo "a pierwszy z nich to $1 (2)"
fi

# instrukcja case

case $1 in
    start | START)
	echo "opcja START"
    ;;
    stop | STOP)
	echo "opcja STOP"
    ;;
    *)
	echo "podano inny parametr niz START/STOP"
    ;;
esac

# Pętla for

# for nazwa [in lista_słow]
# do
#   lista_poleceń
# done

# for ((wyr1; wyr2; wyr3))
# do
#   lista_poleceń
# done


for I in `cat plik`
do 
  echo "Kopiowanie pliku $I"
  cp -v $I ../kat1/
done

tabl=(1 3 5 7)
for K in ${tabl[*]}
do
    echo $K
done

for ((J=1;J<=5;J++))
do 
    echo $J
done

# polecenie break  	=> Wykonanie pętli 
# zostaje przerwane 
# polecenie continue 	=> Powoduje pominięcie 
# pozostałych instrukcji z pętli 
# i przejście do kolejnej iteracji
