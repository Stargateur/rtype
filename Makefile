##
## Makefile for make in /home/bury_a/rendu/rtype
## 
## Made by Anthony Bury
## Login   <bury_a@epitech.eu>
## 
## Started on  Mon Nov 16 02:02:01 2015 Anthony Bury
## Last update Mon Nov 16 02:16:26 2015 Anthony Bury
##

include			source.mk

OBJ_SERVER	=	$(SRC_SERVER:.cpp=.o)

OBJ_CLIENT	=	$(SRC_CLIENT:.cpp=.o)

NAME_SERVER	?=	rtype_server

NAME_CLIENT	?=	rtype_client

CXX		?=	g++

CXXFLAGS	=	-Iinclude/

ifeq ($(CXX), clang++)
CXXFLAGS	+=	-Weverything -Wno-padded
else
CXXFLAGS	+=	-W -Wall -Wextra
endif

ifeq ($(DEBUG), yes)
CXXFLAGS	+=	-g
endif

all:			$(NAME_SERVER) \
			$(NAME_CLIENT)

$(OBJ_SERVER):		CXXFLAGS += -Iinclude/server

$(OBJ_CLIENT):		CXXFLAGS += -Iinclude/client

$(NAME_SERVER):		$(OBJ_SERVER)
			$(CXX) -o $@ $^

$(NAME_CLIENT):		$(OBJ_CLIENT)
			$(CXX) -o $@ $^

clean:
			@rm -vf $(OBJ_SERVER)
			@rm -vf $(OBJ_CLIENT)

fclean:			clean
			@rm -vf $(NAME_SERVER)
			@rm -vf $(NAME_CLIENT)

re:			fclean all

.PHONY:			clean fclean re
