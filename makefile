OBJS = integer.o real.o string.o
MAIN =  da.o cda.o stack.o queue.o
TESTS = test-da test-stack test-cda test-queue # $(DAtests) $(QUEUEtests) $(CDAtests) $(STACKtests)
OOPTS = -Wall -Wextra -g -c
LOPTS = -Wall -Wextra -g
# DAtests = da-0-0 da-0-1 da-0-2 da-0-3 da-0-4 da-0-5 da-0-6 da-0-7 da-0-8 da-0-9 da-0-10 da-0-11 da-0-12 da-0-13 da-0-14
# QUEUEtests = queue-0-0 queue-0-1 queue-0-2 queue-0-3 queue-0-4 queue-0-5 queue-0-6 queue-0-7 queue-0-8 queue-0-9
# CDAtests = cda-0-0 cda-0-1 cda-0-2 cda-0-3 cda-0-4 cda-0-5 cda-0-6 cda-0-7 cda-0-8 cda-0-9 cda-0-10 cda-0-11 cda-0-12 cda-0-13 cda-0-14
# STACKtests = stack-0-0 stack-0-1 stack-0-2 stack-0-3 stack-0-4 stack-0-5 stack-0-6 stack-0-7 stack-0-8 stack-0-9

all : $(OBJS) $(MAIN) $(TESTS)

test-da : test-da.o integer.o da.o
	gcc $(LOPTS) test-da.o $(OBJS) da.o -o test-da

test-cda : test-cda.o real.o cda.o
	gcc $(LOPTS) test-cda.o $(OBJS) cda.o -o test-cda

test-stack : test-stack.o string.o da.o stack.o
	gcc $(LOPTS) test-stack.o $(OBJS) da.o stack.o -o test-stack

test-queue : test-queue.o integer.o cda.o queue.o
	gcc $(LOPTS) test-queue.o $(OBJS) cda.o queue.o -o test-queue

test-da.o : test-da.c da.h integer.h
	gcc $(OOPTS) test-da.c

test-cda.o : test-cda.c cda.h real.h
	gcc $(OOPTS) test-cda.c

test-stack.o : test-stack.c stack.h string.h
	gcc $(OOPTS) test-stack.c

test-queue.o : test-queue.c queue.h integer.h
	gcc $(OOPTS) test-queue.c

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

test : all
	for x in $(TESTS); do echo -------; echo $$x; echo -------; ./$$x; echo; done

valgrind: all
	for x in $(TESTS); do echo -------; echo valgrind $$x; echo -------; valgrind ./$$x; echo; done

clean :
	rm -f $(OBJS) $(MAIN) $(TESTS) test-*.o

# debug : all
# 	for x in $(DAtests) $(CDAtests) $(STACKtests) $(QUEUEtests); do echo -------; echo $$x; echo -------; ./$$x; echo; done

# valgrind-debug: all
# 	for x in $(DAtests) $(CDAtests) $(STACKtests) $(QUEUEtests); do echo -------; echo valgrind $$x; echo -------; valgrind ./$$x; echo; done

# da: $(DAtests)
# 	for x in $(DAtests); do make $$x; done

# cda: $(CDAtests)
# 	for x in $(CDAtests); do make $$x; done

# queue: $(QUEUEtests)
# 	for x in $(QUEUEtests); do make $$x; done

# stack: $(STACKtests)
# 	for x in $(STACKtests); do make $$x; done

# $(DAtests): %: %.c da.o
# 	gcc $(LOPTS) -o $@ $< $(OBJS) da.o
	
# $(CDAtests): %: %.c cda.o
# 	gcc $(LOPTS) -o $@ $< $(OBJS) cda.o

# $(QUEUEtests): %: %.c queue.o da.o
# 	gcc $(LOPTS) -o $@ $< $(OBJS) queue.o da.o

# $(STACKtests): %: %.c stack.o cda.o
# 	gcc $(LOPTS) -o $@ $< $(OBJS) stack.o cda.o
