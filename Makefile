TARGET=sim
OBJECT=main.o class.o alu.o rom.o instr.o

$(TARGET): $(OBJECT)
	c++ -o $(TARGET) $(OBJECT)
$(OBJECT): %.o: %.cpp
	c++ -c $<

class.o: class.h
main.o: class.h
alu.o: class.h
instr.o: class.h instr.h
rom.o: class.h instr.h

.PHONY: clean

clean:
	rm -rf *.o sim a.out
