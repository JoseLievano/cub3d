#ifndef FT_INPUT_H
# define FT_INPUT_H
# include "../../includes/cub3d.h"

// Tracks keyboard/mouse states
typedef struct s_input {
	bool    w;          // W key pressed
	bool    a;          // A key pressed
	bool    s;          // S key pressed
	bool    d;          // D key pressed
	bool    left;       // Left arrow pressed
	bool    right;      // Right arrow pressed
	bool    esc;        // ESC key pressed
	int     mouse_x;    // Mouse X position (for rotation)
} t_input;

void	ft_input(void);
#endif