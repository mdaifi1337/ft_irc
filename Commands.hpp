#ifndef __COMMANDS_HPP__
#define __COMMANDS_HPP__

#include <vector>
#include <string>
#include "Server.hpp"

// int call_command(Server &serv, User &u, std::vector<std::string> message);

// int AWAY(Server &serv, User &u, std::vector<std::string> message); DONE
// int JOIN(Server &serv, User &u, std::vector<std::string> message);
// int LUSERS(Server &serv, User &u, std::vector<std::string> message);
// int MOTD(Server &serv, User &u, std::vector<std::string> message); // * Configuration file read
// int NOTICE(Server &serv, User &u, std::vector<std::string> message); ALMOST DONE
// int NICK(Server &serv, User &u, std::vector<std::string> message); DONE
// int PART(Server &serv, User &u, std::vector<std::string> message);
// int PING(Server &serv, User &u, std::vector<std::string> message);
// int PONG(Server &serv, User &u, std::vector<std::string> message);
// int PRIVMSG(Server &serv, User &u, std::vector<std::string> message); ALMOST DONE
int QUIT(Server &serv, User &u, std::vector<std::string> message);
// int USER(Server &serv, User &u, std::vector<std::string> message); DONE
// int WHOIS(Server &serv, User &u, std::vector<std::string> message); DONE
// int OPER(Server &serv, User &u, std::vector<std::string> message); DONE
// int PASS(Server &serv, User &u, std::vector<std::string> message); DONE
// int ISON(Server &serv, User &u, std::vector<std::string> message);
// MODE
// TOPIC
//


#endif