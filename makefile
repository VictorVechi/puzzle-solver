CXXFLAGS = -std=c++17 -Iinclude
SRC = ./src/utils/Util.cpp ./src/utils/Board.cpp ./src/algoritmos/Bfs.cpp ./src/algoritmos/Dfs.cpp main.cpp

compile:
	g++ $(CXXFLAGS) $(SRC) -o resolucao