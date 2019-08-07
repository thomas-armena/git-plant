bin/git-plant: src/main.cpp src/Canvas.cpp src/Branch.cpp
	g++ -o bin/git-plant src/main.cpp src/Canvas.cpp src/Branch.cpp -I include