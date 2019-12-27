all:	appointment	run

appointment:main.o	Date.o	fileOps.o	stringOps.o	Appointment.o
	gcc	main.o	Date.o	fileOps.o	stringOps.o	Appointment.o	-o	appointment	

main.o:main.c
	gcc	-c	main.c

Date.o:Date.c	Date.h
	gcc	-c	Date.c

fileOps.o:fileOps.c	fileOps.h
	gcc	-c	fileOps.c

stringOps.o:stringOps.c	stringOps.h
	gcc	-c	stringOps.c

Appointment.o:Appointment.c	Appointment.h
	gcc	-c	Appointment.c
clean:	
	del .*o	appointment.exe
	
run:
	.\appointment			
