BIN = /home/system/MovieBooking/sprint2/CUT/CODE/bin
INC = /home/system/MovieBooking/sprint2/CUT/CODE/inc
SRC = /home/system/MovieBooking/sprint2/CUT/CODE/src
OBJ = /home/system/MovieBooking/sprint2/CUT/CODE/obj

CFLAGS = -c -g -Wall
LFLAGS = -o
GCC = g++
CVFLAGS = -Wall -c -g
IFLAGS = -I $(INC)

all : $(BIN)/moviebooking 

$(OBJ)/main.o : $(SRC)/main.cpp
	$(GCC) $(CFLAGS) $(SRC)/main.cpp $(IFLAGS)
	mv *.o /home/system/MovieBooking/sprint2/CUT/CODE/obj

$(OBJ)/member_def.o : $(SRC)/member_def.cpp
	$(GCC) $(CFLAGS) $(SRC)/member_def.cpp $(IFLAGS)
	mv *.o /home/system/MovieBooking/sprint2/CUT/CODE/obj

$(OBJ)/customer_def.o : $(SRC)/customer_def.cpp
	$(GCC) $(CFLAGS) $(SRC)/customer_def.cpp $(IFLAGS)
	mv *.o /home/system/MovieBooking/sprint2/CUT/CODE/obj


$(OBJ)/booking_def.o : $(SRC)/booking_def.cpp
	$(GCC) $(CFLAGS) $(SRC)/booking_def.cpp $(IFLAGS)
	mv *.o /home/system/MovieBooking/sprint2/CUT/CODE/obj

$(BIN)/moviebooking : $(OBJ)/main.o $(OBJ)/member_def.o $(OBJ)/customer_def.o $(OBJ)/booking_def.o 
	$(GCC) $(OBJ)/main.o $(OBJ)/member_def.o $(OBJ)/customer_def.o $(OBJ)/booking_def.o $(LFLAGS) $(BIN)/moviebooking

clean:
         rm *.o
         rm *.gch

