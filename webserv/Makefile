NAME = webserv
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
OBJ_DIR = objs/
RM = rm -rf

OBJS =  $(SRCS_OBJS) $(CONFIG_OBJS)  $(REQUEST_OBJS)  $(RESPON_OBJS) $(UTILS_OBJS) $(WEBSERV_OBJS)

#### FILES

#### SRCS FILES

SRCS_DIR = srcs/
SRCS_FILES = main.cpp 

SRCS_SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
SRCS_OBJS = $(addprefix $(OBJ_DIR), $(SRCS_FILES:.cpp=.o))

$(OBJ_DIR)%.o: $(SRCS_DIR)%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -o $@ -c $<

#### WEBSERV FILES

WEBSERV_DIR = srcs/
WEBSERV_FILES = Webserv.cpp
WEBSERV_DIR2 = includes/
WEBSERV_HEADERS = Webserv.hpp

WEBSERV_SRCS = $(addprefix $(WEBSERV_DIR), $(WEBSERV_FILES))
WEBSERV_INCLUDES = $(addprefix $(WEBSERV_DIR2), $(WEBSERV_HEADERS))
WEBSERV_OBJS = $(addprefix $(OBJ_DIR), $(WEBSERV_FILES:.cpp=.o))

$(OBJ_DIR)%.o: $(WEBSERV_DIR)%.cpp $(WEBSERV_DIR)%.hpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -o $@ -c $<

#### UTILS FILES

UTILS_DIR = srcs/utils/
UTILS_FILES = Utils.cpp
UTILS_DIR2 = includes/
UTILS_HEADERS = Utils.hpp

UTILS_SRCS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))
UTILS_INCLUDES = $(addprefix $(UTILS_DIR2), $(UTILS_HEADERS))
UTILS_OBJS = $(addprefix $(OBJ_DIR), $(UTILS_FILES:.cpp=.o))

$(OBJ_DIR)%.o: $(UTILS_DIR)%.cpp $(UTILS_DIR)%.hpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -o $@ -c $<

#### CONFIG FILES

CONFIG_DIR = srcs/config/
CONFIG_FILES = Config.cpp
CONFIG_DIR2 = includes/
CONFIG_HEADERS = Request.hpp

CONFIG_SRCS = $(addprefix $(CONFIG_DIR), $(CONFIG_FILES))
CONFIG_INCLUDES = $(addprefix $(CONFIG_DIR2), $(CONFIG_HEADERS))
CONFIG_OBJS = $(addprefix $(OBJ_DIR), $(CONFIG_FILES:.cpp=.o))

$(OBJ_DIR)%.o: $(CONFIG_DIR)%.cpp $(CONFIG_DIR)%.hpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -o $@ -c $<

#### REQUEST FILES

REQUEST_DIR = srcs/request/
REQUEST_FILES = Request.cpp
REQUEST_DIR2 = includes/
REQUEST_HEADERS = Request.hpp

REQUEST_SRCS = $(addprefix $(REQUEST_DIR), $(REQUEST_FILES))
REQUEST_INCLUDES = $(addprefix $(REQUEST_DIR2), $(REQUEST_HEADERS))
REQUEST_OBJS = $(addprefix $(OBJ_DIR), $(REQUEST_FILES:.cpp=.o))

$(OBJ_DIR)%.o: $(REQUEST_DIR)%.cpp $(REQUEST_DIR)%.hpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -o $@ -c $<

#### RESPON FILES

RESPON_DIR = srcs/response/
RESPON_FILES = Response.cpp
RESPON_DIR2 = includes/
RESPON_HEADERS = Response.hpp

RESPON_SRCS = $(addprefix $(RESPON_DIR), $(RESPON_FILES))
RESPON_INCLUDES = $(addprefix $(RESPON_DIR2), $(RESPON_HEADERS))
RESPON_OBJS = $(addprefix $(OBJ_DIR), $(RESPON_FILES:.cpp=.o))

$(OBJ_DIR)%.o: $(RESPON_DIR)%.cpp $(RESPON_DIR)%.hpp 
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -o $@ -c $<


#### RULES

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
