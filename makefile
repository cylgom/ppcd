ppcd : main.o ppcd.o
	g++ -o ppcd main.o ppcd.o

main.o : ppcd.o main.cpp commondefs.h
	g++ -std=c++03 -pedantic -Wall -fpermissive -c main.cpp -o main.o

ppcd.o : ppcd.cpp ppcd.h commondefs.h
	g++ -std=c++03 -pedantic -Wall -fpermissive -c ppcd.cpp -o ppcd.o

clean :
	rm -rf main.o ppcd.o ppcd
