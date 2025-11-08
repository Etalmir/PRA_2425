Point2D.o: Point2D.cpp Point2D.h
	g++ -c Point2D.cpp -o Point2D.o

bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ testPoint2D.cpp Point2D.o -o bin/testPoint2D

Shape.o: Shape.cpp Shape.h Point2D.h
	g++ -c Shape.cpp -o Shape.o