all:gammafunc.pdf

gammafunc.x:gammafunc.cpp
	g++ gammafunc.cpp -o gammafunc.x

gammafunc.txt: gammafunc.x
	./gammafunc.x 1 > gammafunc.txt

gammafunc.pdf:script.gp gammafunc.txt
	gnuplot script.gp

