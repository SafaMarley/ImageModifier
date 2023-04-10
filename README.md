# ImageModifier

Execute "make filter" from project's directory to compile the program.

Once compiled you can run the program with proper parameters
./filter -{function indicator} {input path} {output path}

Example:
</br>
Original
</br>
![alt text](inputImages/tower.bmp)
</br>
</br>
Ignore Red Channel
</br>
./filter -1 inputImages/tower.bmp outputImages/1Tower.bmp
would produce;
</br>
![alt text](outputImages/1tower.bmp)
</br>
</br>
Ignore Green Channel
</br>
./filter -2 inputImages/tower.bmp outputImages/2Tower.bmp
would produce;
</br>
![alt text](outputImages/2tower.bmp)
</br>
</br>
Ignore Blue Channel
</br>
./filter -3 inputImages/tower.bmp outputImages/3Tower.bmp
would produce;
</br>
![alt text](outputImages/3tower.bmp)
</br>
</br>
Blur
</br>
./filter -b inputImages/tower.bmp outputImages/bTower.bmp
would produce;
</br>
![alt text](outputImages/btower.bmp)
</br>
</br>
Edge Detection
</br>
./filter -e inputImages/tower.bmp outputImages/eTower.bmp
would produce;
</br>
![alt text](outputImages/etower.bmp)
</br>
</br>
Grayscale
</br>
./filter -g inputImages/tower.bmp outputImages/gTower.bmp
would produce;
</br>
![alt text](outputImages/gtower.bmp)
</br>
</br>
Reverse
</br>
./filter -r inputImages/tower.bmp outputImages/rTower.bmp
would produce;
</br>
![alt text](outputImages/rtower.bmp)
</br>
</br>
Inverse
</br>
./filter -i inputImages/tower.bmp outputImages/iTower.bmp
would produce;
</br>
![alt text](outputImages/itower.bmp)
</br>
</br>
Lighten
</br>
./filter -l inputImages/tower.bmp outputImages/lTower.bmp
would produce;
</br>
![alt text](outputImages/ltower.bmp)
</br>
</br>
Fade
</br>
./filter -f inputImages/tower.bmp outputImages/fTower.bmp
would produce;
</br>
![alt text](outputImages/ftower.bmp)
</br>
</br>
Hallucinate
</br>
./filter -h inputImages/tower.bmp outputImages/hTower.bmp
would produce;
</br>
![alt text](outputImages/htower.bmp)
</br>
</br>
Sort
</br>
./filter -s inputImages/tower.bmp outputImages/sTower.bmp
would produce;
</br>
![alt text](outputImages/stower.bmp)