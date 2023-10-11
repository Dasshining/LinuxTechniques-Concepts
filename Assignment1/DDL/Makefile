TARGET: exe
exe:evaluation.o libdll.a
	gcc evaluation.o -o exe -L . libdll.a -ldll
libdll.a: dll.o diff.o
	ar rs libdll.a dll.o diff.o
dll.o: dll.c
	gcc -c dll.c -o dll.o
diff.o: diff.c
	gcc -c diff.c -o diff.o
evaluation.o: evaluation.c
	gcc -c -I dll -I diff evaluation.c -o evaluation.o
clean:
	rm diff.o
	rm dll.o
	rm evaluation.o
	rm libdll.a
	rm exe
