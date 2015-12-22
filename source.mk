##
## source.mk for make in /home/bury_a/rendu/rtype
## 
## Made by Anthony Bury
## Login   <bury_a@epitech.eu>
## 
## Started on  Mon Nov 16 02:02:18 2015 Anthony Bury
## Last update Tue Dec 22 17:25:40 2015 Antoine Plaskowski
##

DIR		=		source/

DIR_SERVER	=		$(DIR)server/

DIR_CLIENT	=		$(DIR)client/

DIR_ITIME	=		$(DIR)itime/

DIR_ISOCKET	=		$(DIR)isocket/

DIR_IPROTOCOL	=		$(DIR)iprotocol/

DIR_THREADPOOL	=		$(DIR_SERVER)/threadPool/

SRC		+=		$(DIR_ISOCKET)ISelect.cpp
SRC		+=		$(DIR_ISOCKET)Select.cpp
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
SRC		+=		$(DIR_ISOCKET)IUDP_client.cpp
SRC		+=		$(DIR_ISOCKET)UDP_client.cpp

SRC		+=		$(DIR_IPROTOCOL)ITCP_protocol.cpp
SRC		+=		$(DIR_IPROTOCOL)TCP_protocol.cpp
SRC		+=		$(DIR_IPROTOCOL)ATCP_packet.cpp
SRC		+=		$(DIR_IPROTOCOL)TCP_packet_recv.cpp
SRC		+=		$(DIR_IPROTOCOL)TCP_packet_send.cpp
#SRC		+=		$(DIR_IPROTOCOL)IUDP_protocol.cpp
#SRC		+=		$(DIR_IPROTOCOL)UDP_protocol.cpp
SRC		+=		$(DIR_IPROTOCOL)AUDP_packet.cpp
SRC		+=		$(DIR_IPROTOCOL)UDP_packet_recv.cpp
#SRC		+=		$(DIR_IPROTOCOL)UDP_packet_send.cpp

SRC		+=		$(DIR_ITIME)ITime.cpp
SRC		+=		$(DIR_ITIME)Time.cpp

SRC_SERVER	+=		$(DIR_SERVER)main.cpp
SRC_SERVER	+=		$(DIR_SERVER)Server.cpp
SRC_SERVER	+=		$(DIR_SERVER)Client.cpp
SRC_SERVER	+=		$(DIR_SERVER)IEntite.cpp
SRC_SERVER	+=		$(DIR_SERVER)IGame.cpp
SRC_SERVER	+=		$(DIR_SERVER)BasicGame.cpp
SRC_SERVER	+=		$(DIR_SERVER)PortGenerator.cpp
SRC_SERVER	+=		$(DIR_THREADPOOL)Task.cpp
SRC_SERVER	+=		$(DIR_THREADPOOL)ThreadPool.cpp

SRC_CLIENT	+=		$(DIR_CLIENT)main.cpp
SRC_CLIENT	+=		$(DIR_CLIENT)View.cpp
SRC_CLIENT	+=		$(DIR_CLIENT)Controller.cpp
SRC_CLIENT	+=		$(DIR_CLIENT)Model.cpp
SRC_CLIENT	+=		$(DIR_CLIENT)Button.cpp
SRC_CLIENT	+=		$(DIR_CLIENT)Text.cpp
SRC_CLIENT	+=		$(DIR_CLIENT)Sprite.cpp
SRC_CLIENT	+=		$(DIR_CLIENT)AElement.cpp
