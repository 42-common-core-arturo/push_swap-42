NAME=push_swap
CODEDIR=. srcs
INCLUDEDIR=. ./include/
CC=cc
DEPFLAGS=-MP -MD
CFLAGS=-Wall -Wextra -g $(foreach D,$(INCLUDEDIR),-I$(D)) $(DEPFLAGS)
CFILES=$(foreach D,$(CODEDIR),$(wildcard $(D)/*.c))
OBJ=$(patsubst %.c,%.o,$(CFILES))
DEPFILES=$(patsubst %.c,%.d,$(CFILES))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(NAME) $(OBJ) $(DEPFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPFILES)
