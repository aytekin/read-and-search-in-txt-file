hepsi: derle calistir oynat
derle:
	g++ -I include/ -o lib/Agac.o -c src/Agac.cpp
	g++ -I include/ -o lib/Liste.o -c src/Liste.cpp
	g++ -I include/ -o lib/Islem.o -c src/Islem.cpp
calistir:
	g++ -I include/ -o bin/cikti lib/Liste.o lib/Islem.o lib/Agac.o src/Test.cpp
oynat:
	bin/cikti
	