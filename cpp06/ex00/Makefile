_END=\033[0m
_RED=\033[31m
_GREEN=\033[32m
_YELLOW=\033[33m
_CYAN=\033[36m

NAME = Converter

SRC =	main.cpp \
		ScalarConverter.cpp

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++98

ifeq ($(DEBUG),1)
CXXFLAGS += -ggdb
else
CXXFLAGS += -Werror
endif

INC = -Iinc

SRC_DIR = src
OBJ_DIR = obj

ECHO	= @printf "%b\n" "$(1)"

all: $(NAME)

$(NAME): $(OBJ)
	$(call ECHO,$(_GREEN)Compiling $(OBJ)...$(_END))
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $@

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(call ECHO,$(_CYAN)Compiling $<...$(_END))
	@$(CXX) -o $@ -c $< $(CXXFLAGS) $(INC)

clean:
	$(call ECHO,$(_YELLOW)Cleaning $(OBJ)...$(_END))
	@rm -rf $(OBJ_DIR)

fclean: clean
	$(call ECHO,$(_RED)Cleaning $(NAME)...$(_END))
	@rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)

.PHONY: all clean fclean re
