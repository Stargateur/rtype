##
## source.mk for make in /home/bury_a/rendu/rtype
## 
## Made by Anthony Bury
## Login   <bury_a@epitech.eu>
## 
## Started on  Mon Nov 16 02:02:18 2015 Anthony Bury
## Last update Mon Nov 23 11:38:14 2015 Anthony Bury
##

DIR		=		source/

DIR_SERVER	=		$(DIR)server/

DIR_CLIENT	=		$(DIR)client/

DIR_ITIME	=		$(DIR)itime/

DIR_ISOCKET	=		$(DIR)isocket/

SRC_SERVER	+=		$(DIR_SERVER)main.cpp
SRC_SERVER	+=		$(DIR_SERVER)StartUp.cpp
SRC_SERVER	+=		$(DIR_ITIME)ITime.cpp
SRC_SERVER	+=		$(DIR_ITIME)Time.cpp
SRC_SERVER	+=		$(DIR_ISOCKET)ISocket.cpp
SRC_SERVER	+=		$(DIR_ISOCKET)ASocket.cpp
SRC_SERVER	+=		$(DIR_ISOCKET)IStandard.cpp
SRC_SERVER	+=		$(DIR_ISOCKET)Standard.cpp
SRC_SERVER	+=		$(DIR_ISOCKET)ITCP_client.cpp
SRC_SERVER	+=		$(DIR_ISOCKET)TCP_client.cpp
SRC_SERVER	+=		$(DIR_ISOCKET)ITCP_server.cpp
SRC_SERVER	+=		$(DIR_ISOCKET)TCP_server.cpp
SRC_SERVER	+=		$(DIR_ISOCKET)IUDP_server.cpp
SRC_SERVER	+=		$(DIR_ISOCKET)UDP_server.cpp
SRC_SERVER	+=		$(DIR_ISOCKET)IAddress.cpp
SRC_SERVER	+=		$(DIR_ISOCKET)Address.cpp

SRC_CLIENT	+=		$(DIR_CLIENT)main.cpp
SRC_CLIENT	+=		$(DIR_CLIENT)IGraph.cpp
SRC_CLIENT	+=		$(DIR_CLIENT)Graph.cpp
