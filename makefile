OBJS = integer.o real.o string.o
MAIN =  da.o cda.o stack.o queue.o
OOPTS = -Wall -Wextra -g -c
LOPTS = -Wall -Wextra -g
TESTDIR = testing/
TESTS = $(sort $(basename $(notdir $(wildcard $(TESTDIR)*.c)))) # $(DAtests) $(QUEUEtests) $(CDAtests) $(STACKtests) # test-da test-stack test-cda test-queue
# DAtests = da-0-1 da-0-2 da-0-3 da-0-4 da-0-5 da-0-6 da-0-7 da-0-8 da-0-9 da-0-10 da-0-11 da-0-13 da-0-14 da-0-15 da-0-16 da-0-17 da-0-18
# QUEUEtests = queue-0-0 queue-0-1 queue-0-2 queue-0-4 queue-0-5 queue-0-6 queue-0-7 queue-0-8 queue-0-9
# CDAtests = cda-0-0 cda-0-1 cda-0-2 cda-0-3 cda-0-4 cda-0-5 cda-0-6 cda-0-7 cda-0-8 cda-0-10 cda-0-11 cda-0-12 cda-0-13 cda-0-14 cda-0-15 cda-0-16 cda-0-17 cda-0-19 cda-0-21
# STACKtests = stack-0-0 stack-0-1 stack-0-2 stack-0-3 stack-0-5 stack-0-6 stack-0-7 stack-0-8 stack-0-9 stack-0-10

all : $(OBJS) $(MAIN)
	cp -f *.o $(TESTDIR)
	cp -f *.h $(TESTDIR)

stack.o : stack.c stack.h
	gcc $(OOPTS) stack.c

queue.o : queue.c queue.h cda.h
	gcc $(OOPTS) queue.c

da.o : da.c da.h
	gcc $(OOPTS) da.c

cda.o : cda.c cda.h
	gcc $(OOPTS) cda.c

integer.o : integer.c integer.h
	gcc $(OOPTS) integer.c

real.o : real.c real.h
	gcc $(OOPTS) real.c

string.o : string.c string.h
	gcc $(OOPTS) string.c

$(TESTS): %: $(TESTDIR)%.c all
	gcc $(LOPTS) -o $(TESTDIR)$@ $< $(OBJS) $(MAIN)

test : all $(TESTS)
	for x in $(TESTS); do \
		echo; echo -------; echo $$x.expected; echo -------; cat $(TESTDIR)$$x.expected; \
		./$(TESTDIR)$$x > $(TESTDIR)$$x.yours; \
		echo -------; echo $$x.yours; echo -------; cat $(TESTDIR)$$x.yours; echo -------; \
		cmp --silent $(TESTDIR)$$x.expected $(TESTDIR)$$x.yours && echo "PASSED" || echo "FAILED"; echo -------; \
	done

valgrind: all $(TESTS)
	for x in $(TESTS); do \
		valgrind --log-file=$(TESTDIR)$$x.valgrind $(TESTDIR)$$x; \
		echo; echo -------; echo $$x.valgrind; echo -------;  cat $(TESTDIR)$$x.valgrind; echo; \
	done

clean :
	rm -f $(OBJS) $(MAIN) $(TESTS) test-*.o