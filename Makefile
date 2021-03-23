XX=g++
CFLAGS = -Wall -O
TARGET = Uauto

$(TARGET):main.o LED.o Copy.o 
	$(CXX) $(CFLAGS) main.o LED.o Copy.o -o $(TARGET)

main.o:main.cpp LED.cpp Copy.cpp
	$(CXX) $(CFLAGS) -c main.cpp -o main.o

LED.o:LED.cpp LED.h
	$(CXX) $(CFLAGS) -c LED.cpp -o LED.o

Copy.o:Copy.cpp Copy.h
	$(CXX) $(CFLAGS) -c Copy.cpp -o Copy.o

clean:
	rm -rf *.o $(TARGET)

