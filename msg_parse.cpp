#include "msg_parse.hpp"
#include "User.hpp"


std::string	erase_CR_LF(std::string buff)
{
	size_t pos = std::string::npos;
    while ((pos  = buff.find("\r\n") )!= std::string::npos)
        buff.erase(pos, 2);
	return (buff);
}

msg_parse	message_splitter(char *&buffer, int &ret, msg_parse &parsed_command)
{
	std::string buff = buffer;
	buff = erase_CR_LF(buffer); // DEBATABLE coz message chould have only one cr_lf
	// msg_parse parse(buff);
	parsed_command.set_msg(buff);
	if (!parsed_command.parser())
		ret = 0;
	// print_command(parsed_command);
	// parsed_command = parse;
	// std::cout << "message parser command|" << parsed_command.get_cmd() << "|" << std::endl;
	// if (!parsed_command.get_cmd_params().empty())
	// {
	// 	for (std::vector<char *>::iterator it = parsed_command.get_cmd_params().begin(); it != parsed_command.get_cmd_params().end(); it++)
	// 	{
	// 		std::cout << "Param |" << *it << "|" << std::endl;
	// 	}
	// }
	// std::cout << "message parser additional param |" << parsed_command.get_additional_param() << "|" << std::endl;
	return(parsed_command);
}

std::string msg_parse::get_msg(void)
{
	return (msg);
}

void msg_parse::set_msg(std::string buff)
{
	msg = buff;
}

msg_parse::msg_parse( void) : cmd() , cmd_params() , space_par() , msg()
{
}

msg_parse::msg_parse(std::string buffer) : cmd() , cmd_params() , space_par()
{
	msg = buffer;
}

int	msg_parse::command_checker(int *idx)
{
	int	pos;
	for (; msg[*idx] && msg[*idx] != ' '; (*idx)++)
	{
		if (!isupper(msg[*idx]))
		{
			std::cerr << "Command missing" << std::endl;
			pos = msg.find(" ");
			cmd = msg.substr(0, pos);
			//an error MUST be sent back to the client and the parsing terminated
			return (0);
		}
	}
	if (*idx)
		cmd = msg.substr(0, *idx);
	return (1);
}

std::string msg_parse::get_additional_param( void)
{
	return (space_par);
}

void msg_parse::params(int idx, char **tab)
{
	char *tmp_msg = (char *)msg.c_str() + idx;

	*tab = strtok(tmp_msg, " ");
	while (*tab && *tab[0] != ':')
	{
		cmd_params.push_back(*tab);
		*tab = strtok(NULL, " ");
	}
}

void	msg_parse::additional_param(char *tab)
{

	if (tab && tab[0] == ':')
	{
		while (tab)
		{
			space_par += tab;
			tab = strtok(NULL, " ");
			if (tab)
				space_par += " ";
		}
		space_par.erase(0, 1);
	}
}

int	msg_parse::parser( void)
{
	int index = 0;

	if (msg.empty())
		std::cout << "Empty msg" << std::endl; //should be silently ignored
	if (!command_checker(&index))
		return (0);
	char *tab;
	params(index, &tab);
	additional_param(tab);
	return (1);
}

std::string msg_parse::get_cmd( void)
{
	return (cmd);
}
std::vector<char *> msg_parse::get_cmd_params( void)
{
	return (cmd_params);
}

msg_parse &msg_parse::operator=(const msg_parse & f)
{
	this->msg = f.msg;
	this->cmd = f.cmd;
	this->cmd_params = f.cmd_params;
	this->space_par = f.space_par;
	return (*this);
}

msg_parse::~msg_parse()
{

}

// int main(int c, char **v)
// {
// 	if (c > 1)
// 	{
// 		std::string conc_msg;
// 		std::string space = " ";
// 		for (int i = 1; i < c; i++)
// 		{
// 			conc_msg += v[i] + space;
// 		}
// 		msg_parse msg(conc_msg);
// 		msg.parser();
// 		// std::cout << msg.get_msg() << std::endl;
// 		return (0);
// 	}
// 	std::cout << "Add some arguments bb" << std::endl;
// 	return (0);
// }