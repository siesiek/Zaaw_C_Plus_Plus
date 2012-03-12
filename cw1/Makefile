GTEST_DIR = /home/siesiek/Pobrane/gtest-1.6.0

test:
	#g++ -I${GTEST_DIR}/include -I${GTEST_DIR} -c ${GTEST_DIR}/src/gtest-all.cc
	#ar -rv libgtest.a gtest-all.o
	g++ -I$(GTEST_DIR)/include test.cpp class.h libgtest.a -o test
	make run

run:
	./test
