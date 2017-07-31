FINAL:=main
OBJECT:=main.o menu.o tool.o teacher.o root.o student.o
OPTIONS:=-g -Wall
CC:=gcc

$(FINAL):$(OBJECT)
	$(CC) $^ -o $@ $(OPTIONS)

%.o:%.c
	$(CC) -c $< -o $@ $(OPTIONS)
clean:
	rm -rvf $(OBJECT) $(FINAL) 
cleant:
	rm -rvf *.txt
built:
	touch student.txt teacher.txt
