# first figure out which platform it is and fill in the libraries
#
LIBS ::=

ifeq ($(OS), Windows_NT)
	LIBS += -lglfw3 -lgdi32 -lopengl32
	LIBS += -L./lib/windows
else

ifeq ($(shell uname), Linux)
	LIBS += -lglfw3 -lXxf86vm -lXrandr -lXi  -lrt -lm -ldl -lX11 -lpthread -lxcb -lXau -lXdmcp -lGL
	LIBS += -L./lib/linux
endif

endif

CC ::= gcc
OPT ::= -O0
INCLUDE ::= -I./include/ -I./lib -I./lib/ncug 
CFLAGS ::= -Wall -Wextra $(OPT) 

# source and others

SRC ::= ./src/*.c ./lib/ncug/*.c 
OBJDIR ::= ./obj
BINARY ::= ./program


all: $(BINARY)
	@echo "done !"

$(BINARY): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(BINARY) $(LIBS) $(INCLUDE)

# $(OBJDIR)/%.o: $(SRC)/%.c $(OBJDIR)
# 	cd $(OBJDIR) ; $(CC) -c ../$< $(CFLAGS) ;

# $(OBJDIR): $(CUGAPI)
# 	mkdir $(OBJDIR)
