#ifndef ERROR_H
# define ERROR_H

int     ui_error(const char *error_msg);
void    *ui_null_error(const char *error_msg);
int		ui_perror(const char *error_msg);
void	*ui_null_perror(const char *error_msg);

#endif