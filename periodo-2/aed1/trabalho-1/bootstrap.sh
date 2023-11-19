gcc -c ./modules/datasource.c -o ./dist/datasource.o
gcc -c ./modules/presenter.c -o ./dist/presenter.o
gcc -c main.c -o ./dist/main.o
gcc main.c ./modules/datasource.c ./modules/presenter.c -o ./dist/a.out
./dist/a.out