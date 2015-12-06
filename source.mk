##
## source.mk for make in /home/bury_a/rendu/rtype
## 
## Made by Anthony Bury
## Login   <bury_a@epitech.eu>
## 
## Started on  Mon Nov 16 02:02:18 2015 Anthony Bury
## Last update Sun Dec  6 04:48:53 2015 Antoine Plaskowski
##

DIR		=		source/

DIR_SERVER	=		$(DIR)server/

DIR_CLIENT	=		$(DIR)client/

DIR_ITIME	=		$(DIR)itime/

DIR_ISOCKET	=		$(DIR)isocket/

DIR_IPROTOCOL	=		$(DIR)iprotocol/

SRC		+=		$(DIR_ISOCKET)ISocket.cpp
SRC		+=		$(DIR_ISOCKET)ASocket.cpp
SRC		+=		$(DIR_ISOCKET)IStandard.cpp
SRC		+=		$(DIR_ISOCKET)Standard.cpp
SRC		+=		$(DIR_ISOCKET)ITCP_client.cpp
SRC		+=		$(DIR_ISOCKET)TCP_client.cpp
SRC		+=		$(DIR_ISOCKET)ITCP_server.cpp
SRC		+=		$(DIR_ISOCKET)TCP_server.cpp
SRC		+=		$(DIR_ISOCKET)IUDP_server.cpp
SRC		+=		$(DIR_ISOCKET)UDP_server.cpp
SRC		+=		$(DIR_ISOCKET)IAddress.cpp
SRC		+=		$(DIR_ISOCKET)Address.cpp
SRC		+=		$(DIR_IPROTOCOL)ITCP_protocol.cpp
SRC		+=		$(DIR_IPROTOCOL)ATCP_packet.cpp
SRC		+=		$(DIR_IPROTOCOL)TCP_packet_recv.cpp
SRC		+=		$(DIR_IPROTOCOL)TCP_packet_send.cpp

SRC_SERVER	+=		$(DIR_SERVER)main.cpp
SRC_SERVER	+=		$(DIR_SERVER)Server.cpp
SRC_SERVER	+=		$(DIR_SERVER)Client.cpp
SRC_SERVER	+=		$(DIR_ITIME)ITime.cpp
SRC_SERVER	+=		$(DIR_ITIME)Time.cpp

SRC_CLIENT	+=		$(DIR_CLIENT)main.cpp
SRC_CLIENT	+=		$(DIR_CLIENT)IGraph.cpp
SRC_CLIENT	+=		$(DIR_CLIENT)Graph.cpp
