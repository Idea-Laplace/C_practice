#include <string.h>

void call_cmd(char *cmd) {
	const struct cmd_match {
		char *cmd_name;
		void (*cmd_pointer)(void);
	} file_cmd[] = {
		{"new", new_cmd},
		{"open", open_cmd},
		{"close", close_cmd},
		{"close_all", close_all_cmd},
		{"save", save_cmd},
		{"save_as", save_as_cmd},
		{"save_all", save_all_cmd},
		{"print", print_cmd},
		{"exit", exit_cmd}};
	
	struct cmd_match *p;

	for (p = file_cmd; (p - file_cmd) < 9; p++)
		if (strcmp(cmd, p->cmd_name) == 0)
			p->(*cmd_pointer)();
}



