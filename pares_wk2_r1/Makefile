all:workshop2.pdf

workshop2.x:workshop2.cpp
	g++ workshop2.cpp -o workshop2.x

seed_1.txt: workshop2.x
	./workshop2.x 1 5000 3.5 0.4 2.7 4.6 50 > seed_1.txt

seed_2.txt: workshop2.x
	./workshop2.x 2 5000 3.5 0.4 2.7 4.6 50 > seed_2.txt

seed_5.txt: workshop2.x
	./workshop2.x 5 5000 3.5 0.4 2.7 4.6 50 > seed_5.txt	

workshop2.pdf:script.gp seed_1.txt
	gnuplot script.gp

workshop2.pdf:script.gp seed_2.txt
	gnuplot script.gp

workshop2.pdf:script.gp seed_5.txt
	gnuplot script.gp


