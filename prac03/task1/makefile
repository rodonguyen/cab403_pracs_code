# # # [target]: [dependencies]
# # # 	[command]
# hellomake: hellomake.c hellofunction.c
# 	gcc -o hellomake hellomake.c hellofunction.c -I.



# #==========================EX2=============================
# # why are we replacing the extenstions to .o ???

# # The extensions are being replaced to .o 
# # because .o files are compiled versions of the .c files. These object files contain machine code that can be linked together to create the final executable.

# # Benefits:
# # Separate Compilation: By compiling each source code file into an object file separately, you can save time during the development process. When you modify a single source code file, you don't need to recompile the entire program. Instead, you only need to recompile the modified source file and then link it with the existing object files.
# # Modularity: Compiling source code files into object files allows for modularity. Each object file represents a specific module or component of the program. This modular approach makes it easier to manage and maintain large codebases.

# CC=gcc
# CFLAGS=-I.

# # Here, we are replacing .c to .o in the dependencies list. AND the makefile is smart enough to know to compile the .c files into .o files first 
# # before linking them together to create the final executable.
# hellomake: hellomake.o hellofunction.o
# 	$(CC) -o hellomake hellomake.o hellofunction.o


#===========================EX3============================


# # Below is just my explaination
# CC=gcc
# CFLAGS=-I.
# DEPS = hellomake.h    # Macro DEPS (dependencies)
# # Here, we are replacing .c to .o in the dependencies list. AND the makefile is smart enough to know to compile the .c files into .o files first 
# # before linking them together to create the final executable.
# # hellomake: hellomake.o hellofunction.o $(DEPS)
# # 	$(CC) -o hellomake hellomake.o hellofunction.o

# # Step 1: compile the .c files into .o files
# # For every targeted .o file, it depends on the *corresponding* .c file and the DEPS file.
# # Example: hellomake.o: hellomake.c hellomake.h
# %.o: %.c $(DEPS)
# 									$(CC) -c -o $@ 					$< 					$(CFLAGS)
# # it means that   gcc   -c -o hellomake.o hellomake.c -I.


# # Step 2: link the .o files together to create the final executable
# hellomake: hellomake.o hellofunction.o 
# 	$(CC) -o hellomake hellomake.o hellofunction.o
# # ------------------


# CC=gcc
# CFLAGS=-I.
# DEPS = hellomake.h    # Macro DEPS (dependencies)

# # $@ - The file name of the target of the rule.
# # $< - The name of the first item in the dependencies list.
# # [target]: [dependencies]
# # 	[command]

# %.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)
# # $(CC) -c -o $@          $<          $(CFLAGS)
# # example translation:	$(CC) -c -o hellomake.o hellomake.c -I.

# hellomake: hellomake.o hellofunction.o 
# 	$(CC) -o hellomake hellomake.o hellofunction.o

# #--------makefile 4--------
# # This makes 2 more modifications:
# # -  $^ - The names of all the dependencies, with spaces between them.
# # -  Use OBJ instead of listing the .o files directly in the target line.
# CC=gcc
# CFLAGS=-I.
# DEPS = hellomake.h
# OBJ = hellomake.o hellofunction.o 

# %.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)
# 	gcc   -c -o hellomake.o hellomake.c

# hellomake: $(OBJ)
# 	$(CC) -o $@ $^ $(CFLAGS)

# #--------makefile 5--------
OBJS := foo.o bar.o

# link
programName: $(OBJS)
		gcc $(OBJS) -o $@

# pull in dependency info for *existing* .o files, so the object files know what their dependencies are
-include $(OBJS:.o=.d)

# compile and generate dependency info
%.o: %.c
		gcc -c $(CFLAGS) $*.c -o $*.o
		gcc -MM $(CFLAGS) $*.c > $*.d

# remove compilation products
clean:
		rm -f programName *.o *.d





# Explanation in foo.d:
# foo.c -> foo.h
# foo.o -> foo.c
# => foo.o -> foo.h
# ==> foo.o -> foo.h foo.c