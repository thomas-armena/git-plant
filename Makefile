bin/git-plant: src/main.cpp src/Canvas.cpp src/Branch.cpp src/Tree.cpp
	g++ -g -o bin/git-plant src/main.cpp src/Canvas.cpp src/Branch.cpp src/Tree.cpp -I include
