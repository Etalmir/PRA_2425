bin/testListArray: testListArray.cpp ListArray.h Generic_list.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

clean:
	rm -f *.o *.gch bin 

