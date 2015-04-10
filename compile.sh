echo "# --------------------------------------------------- #"

g++ -O2 -o ./bin/stacker ./source/main.cpp
cp ./bin/stacker ./web_gui
cd web_gui
../bin/stacker

echo "# --------------------------------------------------- #"