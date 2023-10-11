TARGET: exe
exe:evaluation.o libtree.a
	gcc evaluation.o -o exe -L . libtree.a -ltree
libtree.a: tree.o diff.o
	ar rs libtree.a tree.o diff.o
tree.o: tree.c
	gcc -c tree.c -o tree.o
diff.o: diff.c
	gcc -c diff.c -o diff.o
evaluation.o: evaluation.c
	gcc -c -I tree -I diff evaluation.c -o evaluation.o
clean:
	rm diff.o
	rm tree.o
	rm evaluation.o
	rm libtree.a
	rm exe
