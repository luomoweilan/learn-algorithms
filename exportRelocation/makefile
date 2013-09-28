## exportRelocation.exe 
## Author: z00189112	Date: 2013/09/28

OBJ = exportRelocation.o redircsym_map.o redircsym_info.o list.o
TARGET = exportRelocation.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	cc -o $@ $(OBJ)

clean:
	rm -rf *.o $(TARGET)
