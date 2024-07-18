Library		= libftprintf

files 	   = ft_printf \
			 ft_putchar \
			 ft_puthex \
			 ft_putnbr \
			 ft_putstr \
			 ft_putunsigned \
			 ft_putptr \
			 ft_itoa \

Compiler	= cc

CmpFlags	= -Wall -Wextra -Werror

OUTN	= $(Library).a

CFILES	= $(files:%=%.c)

OFILES	= $(files:%=%.o)

NAME	= $(OUTN)

$(NAME):
	$(Compiler) $(CmpFlags) -c $(CFILES)
	ar rcs $(OUTN) $(OFILES)

all: $(NAME)

clean:
	rm -f $(NAME)
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
