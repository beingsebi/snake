#!/bin/bash

sudo g++ -c main.cpp && sudo g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system && sudo ./sfml-app