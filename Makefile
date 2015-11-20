##
## Makefile for Makefile in /home/plasko_a/projet/cplusplus/rtype
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Fri Nov 20 04:13:39 2015 Antoine Plaskowski
## Last update Fri Nov 20 04:19:58 2015 Antoine Plaskowski
##

CLIENT		=	rtype_client

SERVER		=	rtype_server

PATH_TIME	=	lib/time/

PATH_SOCKET	=	lib/socket/

PATH_PROTOCOLV1	=	lib/protocolv1/

PATH_DATABASE	=	lib/database/

CXX		?=	g++

RM		=	rm

MAKE		=	make

DEBUG		?=	no

LEVEL		?=	3

COLOR		?=	no

LIB		=	-l dl $(shell pkg-config --libs sfml-graphics sfml-window sfml-system sfml-network)

INCLUDE		=	-I include -I include/server -I include/client -I include/lib
INCLUDE		+=	$(shell pkg-config --cflags sfml-graphics sfml-window sfml-system sfml-network)

CXXFLAGS	+=	-Wall -Wextra -O$(LEVEL)
CXXFLAGS	+=	-ansi -pedantic -std=c++11
CXXFLAGS	+=	$(INCLUDE)

ifeq ($(CXX), clang++)
CXXFLAGS	+=	-Weverything
endif

ifneq ($(DEBUG), no)
CXXFLAGS	+=	-g
endif

ifneq ($(COLOR), no)
CXXFLAGS	+=	-fdiagnostics-color
endif

LDFLAGS		=	$(LIB)

ifeq ($(DEBUG), no)
LDFLAGS		+=	-s
endif

include			source.mk

DPD_SERVER	=	$(SRC_SERVER:.cpp=.dpd)

OBJ_SERVER	=	$(SRC_SERVER:.cpp=.o)

DPD_CLIENT	=	$(SRC_CLIENT:.cpp=.dpd)

OBJ_CLIENT	=	$(SRC_CLIENT:.cpp=.o)

all		:	$(SERVER) $(CLIENT)

$(SERVER)	:	$(OBJ_SERVER)
			$(CXX) $(OBJ_SERVER) -o $(SERVER) $(LDFLAGS)

$(CLIENT)	:	$(OBJ_CLIENT)
			$(CXX) $(OBJ_CLIENT) -o $(CLIENT) $(LDFLAGS)

clean		:
			$(RM) -f $(OBJ_SERVER)
			$(RM) -f $(DPD_SERVER)
			$(RM) -f $(OBJ_CLIENT)
			$(RM) -f $(DPD_CLIENT)

fclean		:	clean
			$(RM) -f $(SERVER)
			$(RM) -f $(CLIENT)

re		:	fclean
			$(MAKE) -C .

%.dpd		:	%.c
			$(CC) -MM $(<) -o $(@) $(CFLAGS) -MT $(<:.c=.o)

%.o		:	%.c
			$(CC) -c $(<) -o $(@) $(CFLAGS)

%.dpd		:	%.cpp
			$(CXX) -MM $(<) -o $(@) $(CXXFLAGS) -MT $(<:.cpp=.o)

%.o		:	%.cpp
			$(CXX) -c $(<) -o $(@) $(CXXFLAGS)

.PHONY		:	all clean fclean re %.dpd %.o

.SUFFIXES	:	.o.c .dpd.c .o.cpp .dpd.cpp

include			$(DPD_SERVER) $(DPD_CLIENT)
