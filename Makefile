

NAME = ft_gkrellm

DEPDIR := .deps
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

CXX_FLAGS = -Wall -Wextra -Werror -g
LINK_FLAGS = -lncurses

SRC = main.cpp NCursesRenderer.cpp IMonitorModule.cpp IMonitorDisplay.cpp HostNameModule.cpp OSInfoModule.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@clang++ $(LINK_FLAGS) -o $(NAME) $^

clean:
	@rm -f $(OBJ)
	@rm -rf ./$(DEPDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

%.o: %.cpp $(DEPDIR)/%.d | $(DEPDIR)
	@clang++ -c $(DEPFLAGS) $(CXX_FLAGS) -o $@ $<

$(DEPDIR): ; @mkdir -p $@

DEPFILES := $(SRC:%.cpp=$(DEPDIR)/%.d)
$(DEPFILES):

include $(wildcard $(DEPFILES))
