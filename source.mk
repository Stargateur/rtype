##
## source.mk for make in /home/bury_a/rendu/rtype
## 
## Made by Anthony Bury
## Login   <bury_a@epitech.eu>
## 
## Started on  Mon Nov 16 02:02:18 2015 Anthony Bury
## Last update Tue Nov 17 16:56:24 2015 Anthony Bury
##

DIR		=		src/

DIR_SERVER	=		$(DIR)server/

DIR_CLIENT	=		$(DIR)client/

SRC_SERVER	+=		$(DIR_SERVER)main.cpp

SRC_CLIENT	+=		$(DIR_CLIENT)main.cpp
SRC_CLIENT	+=		$(DIR_CLIENT)IGraph.cpp
SRC_CLIENT	+=		$(DIR_CLIENT)Graph.cpp
