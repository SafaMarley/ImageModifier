# ImageModifier

Execute "make filter" from project's directory to compile the program.

Once compiled you can run the program with proper parameters
</br>
./filter -{function indicator} {input path} {output path}

Example:
</br>
Original
</br>
![alt text](https://github.com/SafaMarley/ImageModifier/blob/main/inputImages/tower.bmp)
</br>
</br>
Ignore Red Channel
</br>
./filter -1 inputImages/tower.bmp outputImages/1Tower.bmp
would produce;
</br>
![alt text](https://github.com/SafaMarley/ImageModifier/blob/main/outputImages/1Tower.bmp)
</br>
</br>
Ignore Green Channel
</br>
./filter -2 inputImages/tower.bmp outputImages/2Tower.bmp
would produce;
</br>
![alt text](https://github.com/SafaMarley/ImageModifier/blob/main/outputImages/2Tower.bmp)
</br>
</br>
Ignore Blue Channel
</br>
./filter -3 inputImages/tower.bmp outputImages/3Tower.bmp
would produce;
</br>
![alt text](https://github.com/SafaMarley/ImageModifier/blob/main/outputImages/3Tower.bmp)
</br>
</br>
Blur
</br>
./filter -b inputImages/tower.bmp outputImages/bTower.bmp
would produce;
</br>
![alt text](https://github.com/SafaMarley/ImageModifier/blob/main/outputImages/bTower.bmp)
</br>
</br>
Edge Detection
</br>
./filter -e inputImages/tower.bmp outputImages/eTower.bmp
would produce;
</br>
![alt text](https://github.com/SafaMarley/ImageModifier/blob/main/outputImages/eTower.bmp)
</br>
</br>
Grayscale
</br>
./filter -g inputImages/tower.bmp outputImages/gTower.bmp
would produce;
</br>
![alt text](https://github.com/SafaMarley/ImageModifier/blob/main/outputImages/gTower.bmp)
</br>
</br>
Reverse
</br>
./filter -r inputImages/tower.bmp outputImages/rTower.bmp
would produce;
</br>
![alt text](https://github.com/SafaMarley/ImageModifier/blob/main/outputImages/rTower.bmp)
</br>
</br>
Inverse
</br>
./filter -i inputImages/tower.bmp outputImages/iTower.bmp
would produce;
</br>
![alt text](https://github.com/SafaMarley/ImageModifier/blob/main/outputImages/iTower.bmp)
</br>
</br>
Lighten
</br>
./filter -l inputImages/tower.bmp outputImages/lTower.bmp
would produce;
</br>
![alt text](https://github.com/SafaMarley/ImageModifier/blob/main/outputImages/lTower.bmp)
</br>
</br>
Fade
</br>
./filter -f inputImages/tower.bmp outputImages/fTower.bmp
would produce;
</br>
![alt text](https://github.com/SafaMarley/ImageModifier/blob/main/outputImages/fTower.bmp)
</br>
</br>
Hallucinate
</br>
./filter -h inputImages/tower.bmp outputImages/hTower.bmp
would produce;
</br>
![alt text](https://github.com/SafaMarley/ImageModifier/blob/main/outputImages/hTower.bmp)
</br>
</br>
Sort
</br>
./filter -s inputImages/tower.bmp outputImages/sTower.bmp
would produce;
</br>
![alt text](https://github.com/SafaMarley/ImageModifier/blob/main/outputImages/sTower.bmp)
