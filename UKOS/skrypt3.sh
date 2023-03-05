#! /bin/bash
apt-get install w3m lynx links \
>install.log 2>error.log <<stop
T
T
T
stop
 
clear
echo '<HTML>' >strona.html
echo '<HEAD>' >>strona.html
echo '<TITLE>Tytul strony</TITLE>' >>strona.html
echo '</HEAD>' >>strona.html
echo '<BODY>' >>strona.html
echo '<p align=center> 
<br><br><br>
<b>Przykladowa strona internetowa</b>
</p>' >>strona.html
echo '</BODY>' >>strona.html
echo '</HTML>' >>strona.html
echo aby przejść dalej naciśnij enter 

echo 'Strona internetowa uruchmi sie w przegladarce w3m. 
Wyjscie z przeglądarki po naciśnięciu q'
read dalej
w3m strona.html
clear
echo 'Strona internetowa uruchmi sie w przegladarce lynx
Wyjscie z przeglądarki po naciśnięciu q'
read dalej

lynx strona.html

clear
echo 'Strona internetowa uruchmi sie w przegladarce links
Wyjscie z przeglądarki po naciśnięciu q'
read dalej


links strona.html








