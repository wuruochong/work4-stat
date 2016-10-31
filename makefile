filestat: filestat.c
	gcc filestat.c -o filestat

clean:
	rm filestat

run: filestat
	./filestat
