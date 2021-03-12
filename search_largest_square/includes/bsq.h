/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadachi <yadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:10:17 by yadachi           #+#    #+#             */
/*   Updated: 2021/03/10 23:19:37 by yadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct	s_map_info
{
	char		**map;
	char		*charset;
	int			h_len;
	int			w_len;
}				t_map_info;

char			*ft_strdup(char *src);
void			scan_line(char *input);
void			map_normalize(t_map_info *map_info);
int				*find_maxcoor(int **map_num, int w_len, int h_len);
void			fill_full(char **map, int *max_h_w);
void			put_map_error(void);
int				count_col(t_map_info *map_info, char **lines);
int				get_len_firstline(char *str);
int				check_col_len(int len, char *cols);
int				check_col_char(char *cols, char *charset);
int				check_invaild_map(char *cols, t_map_info *t_map);
int				bsq_atoi(char *str, int n);
int				ft_strlen(char *str);
char			*oneline_strdup(char *src);
int				check_first_col(char *str);
int				set_matrix(char **matrix, int w_len, int h_len);
void			put_nbr_rec(int nbr);
void			put_nbr(int nbr);
void			put_2dintmatrix(int **matrix, int w_len, int h_len);
void			put_2dcharmatrix(char **matrix, int w_len, int h_len);
int				**solver(char **map, int w_len, int h_len);
void			determine_num_all
	(char **map, int **map_num, int w_len, int h_len);
void			map_num_init(char **map, int **map_num, int w_len, int h_len);
void			determine_num(int h, int w, int **map_num);
int				**make_2dintmatrix(int w_len, int h_len);
int				check_multi_char(char *cols, char *charset);
char			*oneline_strdup(char *src);
int				get_len_firstline(char *str);
void			map_decode(t_map_info *map_info);
char			*read_file(char *f_name);
int				char_check(char c, char *charset);
int				buf_check(char *buf, t_map_info *map_info);
int				check_header(char *header);
void			start_search_in_main(t_map_info *map_info);
t_map_info		*read_header(char *doc);
t_map_info		*buf_to_map(char *doc, t_map_info *map_info);
t_map_info		*read_perl_output(void);
t_map_info		*file_to_map(char *file_name);

#endif
