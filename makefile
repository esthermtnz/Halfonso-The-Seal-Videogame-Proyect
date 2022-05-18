#MACROS
CC = gcc
CFLAGS = -g -Wall -pedantic -ansi 
CLIB = -lscreen -L$(LIB)

#DIRECCIONES
ARC = ./src/
ARH = ./include/
LIB = ./lib/
ARO = ./obj/
DOXY = ./doc/

#REGLAS
all: halfonso
	./halfonso halfonso.dat log.txt
set_test: $(ARO)set_test.o $(ARO)set.o 
	$(CC) $(CFLAGS) -o$@ $^ 
game_management_test: $(ARO)game_management_test.o $(ARO)game_management.o $(ARO)game.o $(ARO)enemy.o $(ARO)player.o $(ARO)space.o $(ARO)object.o $(ARO)inventory.o $(ARO)link.o $(ARO)set.o 
	$(CC) $(CFLAGS) -o$@ $^ 
space_test: $(ARO)space_test.o $(ARO)space.o $(ARO)set.o
	$(CC) $(CFLAGS) -o$@ $^ 

enemy_test: $(ARO)enemy_test.o $(ARO)enemy.o 
	$(CC) $(CFLAGS) -o$@ $^

link_test: $(ARO)link_test.o $(ARO)link.o 
	$(CC) $(CFLAGS) -o$@ $^

inventory_test: $(ARO)inventory_test.o $(ARO)inventory.o $(ARO)set.o
	$(CC) $(CFLAGS) -o$@ $^

player_test: $(ARO)player_test.o $(ARO)player.o $(ARO)inventory.o $(ARO)set.o
	$(CC) $(CFLAGS) -o$@ $^

object_test: $(ARO)object_test.o $(ARO)object.o
	$(CC) $(CFLAGS) -o$@ $^

halfonso: $(ARO)command.o $(ARO)game.o $(ARO)game_loop.o $(ARO)game_rules.o $(ARO)graphic_engine.o $(ARO)space.o $(ARO)object.o $(ARO)player.o $(ARO)game_management.o $(ARO)set.o $(ARO)enemy.o $(ARO)inventory.o $(ARO)link.o
	$(CC) -o $@ $^ $(CLIB)

$(ARO)command.o: $(ARC)command.c $(ARH)command.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)game.o: $(ARC)game.c $(ARH)game.h $(ARH)command.h $(ARH)space.h $(ARH)types.h $(ARH)object.h $(ARH)player.h $(ARH)inventory.h $(ARH)set.h $(ARH)enemy.h $(ARH)link.h $(ARH)game_management.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)game_loop.o: $(ARC)game_loop.c $(ARH)graphic_engine.h $(ARH)game.h $(ARH)command.h $(ARH)space.h $(ARH)types.h $(ARH)object.h $(ARH)player.h $(ARH)enemy.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)graphic_engine.o: $(ARC)graphic_engine.c $(ARH)graphic_engine.h $(ARH)game.h $(ARH)command.h $(ARH)space.h $(ARH)types.h $(ARH)object.h $(ARH)enemy.h $(ARH)player.h $(ARH)libscreen.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)space.o: $(ARC)space.c $(ARH)space.h $(ARH)types.h $(ARH)set.h 
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)object.o: $(ARC)object.c $(ARH)object.h $(ARH)types.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)game_rules.o: $(ARC)game_rules.c $(ARH)game_rules.h $(ARH)game.h $(ARH)types.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)player.o: $(ARC)player.c $(ARH)space.h $(ARH)types.h $(ARH)player.h $(ARH)inventory.h $(ARH)set.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)game_management.o: $(ARC)game_management.c $(ARH)game_management.h $(ARH)types.h $(ARH)link.h $(ARH)space.h $(ARH)object.h $(ARH)game.h $(ARH)command.h $(ARH)player.h $(ARH)enemy.h $(ARH)inventory.h $(ARH)set.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)set.o: $(ARC)set.c  $(ARH)set.h $(ARH)types.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)enemy.o: $(ARC)enemy.c $(ARH)enemy.h $(ARH)types.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)inventory.o: $(ARC)inventory.c $(ARH)inventory.h $(ARH)types.h $(ARH)set.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)link.o: $(ARC)link.c $(ARH)link.h $(ARH)types.h 
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)set_test.o: $(ARC)set_test.c $(ARH)set_test.h $(ARH)types.h $(ARH)set.h $(ARH)test.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)space_test.o: $(ARC)space_test.c $(ARH)space_test.h $(ARH)types.h $(ARH)space.h $(ARH)set.h $(ARH)test.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)enemy_test.o: $(ARC)enemy_test.c $(ARH)enemy_test.h $(ARH)types.h $(ARH)test.h $(ARH)enemy.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)link_test.o: $(ARC)link_test.c $(ARH)link_test.h $(ARH)types.h $(ARH)test.h $(ARH)link.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)inventory_test.o: $(ARC)inventory_test.c $(ARH)inventory.h $(ARH)types.h $(ARH)set.h $(ARH)inventory_test.h $(ARH)test.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)player_test.o: $(ARC)player_test.c $(ARH)player.h $(ARH)types.h $(ARH)inventory.h $(ARH)set.h $(ARH)player_test.h $(ARH)test.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

$(ARO)object_test.o: $(ARC)object_test.c $(ARH)object_test.h $(ARH)object.h $(ARH)types.h $(ARH)test.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<
$(ARO)game_management_test.o: $(ARC)game_management_test.c $(ARH)game_management_test.h $(ARH)game.h $(ARH)player.h $(ARH)enemy.h $(ARH)object.h $(ARH)space.h $(ARH)link.h $(ARH)inventory.h $(ARH)types.h $(ARH)test.h
	$(CC) $(CFLAGS) -c -o$@ -I$(ARH) $<

doxygen:
	doxygen Doxyfile
cmd:
	./halfonso halfonso.dat log.txt < auto.cmd
clean:
	rm -rf $(ARO)*.o
	rm -rf halfonso
	rm -rf link_test
	rm -rf enemy_test
	rm -rf space_test
	rm -rf inventory_test
	rm -rf player_test
	rm -rf object_test
	rm -rf game_management_test
	rm -rf set_test
