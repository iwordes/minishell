NAME    = libfs
AUTHOR  = iwordes
VERSION = 1.0.2

CC      = gcc
CF      = -Wall -Wextra -Werror -I include

include functions.mk
FN     := $(FN__) $(FN_BOOL) $(FN_HELP) $(FN_INFO) $(FN_OPS)
FN     := $(addsuffix .o,$(addprefix build/,$(FN)))


.PHONY: all
all: $(NAME).a

.PHONY: clean
clean:
	rm -rf build

.PHONY: fclean
fclean: clean
	rm -f $(NAME).a

.PHONY: re
re: fclean all

.PHONY: $(NAME)
$(NAME): $(NAME).a


build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CF) -c -o $@ $<

$(NAME).a: $(FN)
	libtool -static -o $(NAME).a $(FN)
