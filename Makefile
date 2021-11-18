CC	:=	g++

RM	:=	rm -f

NAME	:=	snake

SRC	:=	./src/*.cpp

LFLAGS	:=	-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

OBJ	:=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC)  -o $(NAME) $(SRC) $(LFLAGS)

clean:
	$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:	fclean all


.PHONY:	all clean fclean re
