

NAME = ft_gkrellm

DEPDIR := .deps
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

CXX_FLAGS = -Wall -Wextra -Werror -I ~/.brew/Cellar/sfml/2.5.1/include 
LINK_FLAGS = -lncurses -lsfml-graphics -lsfml-window -lsfml-system -L ~/.brew/Cellar/sfml/2.5.1/lib

SRC = main.cpp NCursesRenderer.cpp IMonitorModule.cpp IMonitorDisplay.cpp HostNameModule.cpp OSInfoModule.cpp \
DateTimeModule.cpp CPUModule.cpp RAMModule.cpp NetworkModule.cpp DisksModule.cpp GUIRender.cpp

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
