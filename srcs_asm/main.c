#include "../libft/includes/libft.h"
#include "../includes/op.h"
#include "../includes/asm.h"
#include <unistd.h>

int main(int argc, char **argv)
{
	t_cmdl cmdl;
	t_lexer lexer_res;
	t_parser parser_res;

	cmdl = cmd_input(argc - 1, argv + 1);
	if (cmdl.er)
		return (1);
	lexer_res = lexer(cmdl);
	close(cmdl.fd);
	if (lexer_res.er)
		return (1);
	parser_res = parser(lexer_res);
	if (parser_res.er)
		return (1); // free ?
	if (cmdl.opt_a)
		display_ast(parser_res);
	else
		ast_to_byte(parser_res);
	// free
	return (0);
}
