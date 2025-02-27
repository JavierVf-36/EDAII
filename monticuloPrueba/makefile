pruebaMonticulo: pruebaMonticulo.o monticulo.o
	gcc -g pruebaMonticulo.o monticulo.o -o pruebaMonticulo
pruebaMonticulo.o: pruebaMonticulo.c monticulo.h 
	gcc -g -c pruebaMonticulo.c pruebaMonticulo.o
monticulo.o: monticulo.c monticulo.h
	gcc -g -c monticulo.c
limpiar:
	rm *.o