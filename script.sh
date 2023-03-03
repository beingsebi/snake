# g++ *.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system && ./sfml-app
g++ *.cpp headers/*.cpp -o snake -lsfml-graphics -lsfml-window -lsfml-system && ./snake