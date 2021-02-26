CFLAGS=--std=c++11


all: self2


self2:
	make -C self_study_book2


test_all: test_self2


test_self2:
	make -C self_study_book2 test


clean:
	make -C self_study_book2 clean
