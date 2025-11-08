bin/testListArray: testListArray.cpp ListArray.h Generic_list.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

ListArray.o: ListArray.cpp Generic_list.h
	g++ -c ListArray.cpp

clean:
	rm -f *.o *.gch bin 

