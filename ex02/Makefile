NAME = Poly 

CPPFLAG = -Wall -Wextra -Werror -std=c++98 -g

OBJ = main.o Base.o

INCLUDE = Serializer.hpp

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CPPFLAG) $(OBJ) -o $(NAME)

%.o : %.cpp $(INCLUDE)
	c++ -c $(CPPFLAG) $< -o $@

clean : 
	rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all

