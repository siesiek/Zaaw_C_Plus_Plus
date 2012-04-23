main:
	g++ main.cpp Task.cpp TodoList.cpp ProgramMenu.cpp -o program.x
	g++ TaskTest.cpp TaskTestRunner.cpp Task.cpp -o test1.x -lcppunit
	g++ ListTest.cpp ListTestRunner.cpp Task.cpp TodoList.cpp -o test2.x -lcppunit
	
run:
	./program.x
	
test1:
	./test1.x
	
test2:
	./test2.x
