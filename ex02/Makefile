NAME = EX02

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJS_DIR = objs

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all : $(NAME)
$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	
$(OBJS_DIR)/%.o : %.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	rm -rf $(OBJS_DIR)

re : fclean all

.PHONY : all clean fclean re