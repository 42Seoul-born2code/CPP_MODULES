	CC	=	c++
ifdef DEBUG
	CFLAGS	=	-std=c++98 -g3 -fsanitize=address
else ifdef LEAKS
	CFLAGS	=	-std=c++98 -g
else
	CFLAGS	=	-std=c++98 -Wall -Wextra -Werror
endif

NAME	=	outfile
SRC		=	main.cpp					\
			AForm.cpp					\
			Bureaucrat.cpp				\
			PresidentialPardonForm.cpp	\
			RobotomyRequestForm.cpp		\
			ShrubberyCreationForm.cpp	\
			Intern.cpp

OBJ		=	$(SRC:%.cpp=%.o)

%.o	:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean
	make all

.PHONY: debug
debug:
	make DEBUG=1 all

.PHONY: leaks
leaks:
	make LEAKS=1 all