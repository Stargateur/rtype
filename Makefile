##
## Makefile for Makefile in /home/plasko_a/projet/cplusplus/rtype
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Fri Nov 20 04:13:39 2015 Antoine Plaskowski
## Last update Thu Dec 24 04:26:12 2015 Antoine Plaskowski
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

LIB_SERVER	=	-l dl -l rt -l pthread

LIB_CLIENT	=	-l dl $(shell pkg-config --libs sfml-graphics sfml-window sfml-system sfml-network) -l rt -l pthread

INCLUDE		=	-I include -I include/itime -I include/isocket -I include/iprotocol -I include/ithread
INCLUDE		+=	-I include/ientite
INCLUDE		+=	$(shell pkg-config --cflags sfml-graphics sfml-window sfml-system sfml-network)

CXXFLAGS	+=	-Wall -Wextra -O$(LEVEL)
CXXFLAGS	+=	-ansi -pedantic -std=c++11
CXXFLAGS	+=	$(INCLUDE)
CXXFLAGS	+=	-Wno-unused-parameter

ifeq ($(CXX), clang++)
CXXFLAGS	+=	-Weverything -Wno-c++98-compat -Wno-padded
endif

ifneq ($(DEBUG), no)
CXXFLAGS	+=	-g -D DEBUG
endif

ifneq ($(COLOR), no)
CXXFLAGS	+=	-fdiagnostics-color
endif

LDFLAGS		=

ifeq ($(DEBUG), no)
LDFLAGS		+=	-s
endif

include			source.mk

DPD		=	$(SRC:.cpp=.dpd)
OBJ		=	$(SRC:.cpp=.o)

DPD_SERVER	=	$(SRC_SERVER:.cpp=.dpd)
OBJ_SERVER	=	$(SRC_SERVER:.cpp=.o)

DPD_CLIENT	=	$(SRC_CLIENT:.cpp=.dpd)
OBJ_CLIENT	=	$(SRC_CLIENT:.cpp=.o)

OBJ_IENTITE	=	$(SRC_IENTITE:.cpp=.o)
DPD_IENTITE	=	$(SRC_IENTITE:.cpp=.dpd)
LIB_IENTITE	=	$(notdir $(OBJ_IENTITE:.o=.so))

all		:	$(SERVER) $(CLIENT) $(LIB_IENTITE)

$(SERVER)	:	CXXFLAGS += -I include/server
$(SERVER)	:	$(OBJ) $(OBJ_SERVER)
			$(CXX) $(OBJ) $(OBJ_SERVER) -o $(SERVER) $(LDFLAGS) $(LIB_SERVER)

$(LIB_IENTITE)	:	CXXFLAGS += -I include/server -fPIC

$(CLIENT)	:	CXXFLAGS += -I include/client
$(CLIENT)	:	$(OBJ) $(OBJ_CLIENT)
			$(CXX) $(OBJ) $(OBJ_CLIENT) -o $(CLIENT) $(LDFLAGS) $(LIB_CLIENT)

clean		:
			$(RM) -f $(OBJ)
			$(RM) -f $(DPD)
			$(RM) -f $(OBJ_SERVER)
			$(RM) -f $(DPD_SERVER)
			$(RM) -f $(OBJ_CLIENT)
			$(RM) -f $(DPD_CLIENT)
			$(RM) -f $(OBJ_IENTITE)
			$(RM) -f $(DPD_IENTITE)

fclean		:	clean
			$(RM) -f $(SERVER)
			$(RM) -f $(CLIENT)
			$(RM) -f $(LIB_IENTITE)

re		:	fclean
			$(MAKE) -C .

%.dpd		:	%.c
			$(CC) -MM $(<) -o $(@) $(CFLAGS) -MT $(<:.c=.o)

%.o		:	%.c
			$(CC) -c $(<) -o $(@) $(CFLAGS)

$(DPD_SERVER)	:	CXXFLAGS += -I include/server
$(DPD_CLIENT)	:	CXXFLAGS += -I include/client
$(DPD_IENTITE)	:	CXXFLAGS += -I include/server

%.so		:	$(DIR_IENTITE)%.o
			$(CXX) -o $(@) $(<) -shared

%.dpd		:	%.cpp
			$(CXX) -MM $(<) -o $(@) $(CXXFLAGS) -MT $(<:.cpp=.o)

%.o		:	%.cpp
			$(CXX) -c $(<) -o $(@) $(CXXFLAGS)

.PHONY		:	all clean fclean re %.dpd %.o

.SUFFIXES	:	.o.c .dpd.c .o.cpp .dpd.cpp

include			$(DPD) $(DPD_SERVER) $(DPD_CLIENT) $(DPD_IENTITE)
