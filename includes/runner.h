/*
** EPITECH PROJECT, 2021
** runner.h
** File description:
** runner
*/

#ifndef RUNNER_H_
    # define RUNNER_H_

    #include <stdbool.h>
    #include <stdlib.h>
    #include <SFML/Audio.h>
    #include <SFML/Window/Export.h>
    #include <SFML/System/Types.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics.h>

struct game_object_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *clock;
    sfTime time_anim;
    float sec;
    float velocity;
};

struct player_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    float seconds;
    bool jump;
    int compt_jump;
    bool win;
    bool lose;
    int score;
    sfText *score_txt;
};

void leave_active(int type_btn, sfRenderWindow *window);
void init_player_skin(struct player_s *player, \
struct player_s **skin);
void display_btn(struct game_object_s **tab_btn, \
sfRenderWindow *window);
void display_text(sfRenderWindow *window, sfText **all_txt);
sfText *set_text_menu(void);
struct game_object_s **all_struct_btn(void);
int handle_event_home(int res_click, sfRenderWindow *window, \
struct game_object_s **tab_btn);
struct game_object_s *set_cursor(int x);
void change_anim_inverse(struct game_object_s **tab_obj, int i);
void change_anim(struct game_object_s **tab_obj, int limit, int shift, int i);
void end_of_runner(sfRenderWindow *window, sfSound **music, \
sfSoundBuffer **buffer, struct player_s *player);
void handle_jump(sfRenderWindow *window, \
struct player_s *player, sfSound **music);
void display_win(sfRenderWindow *window, \
struct game_object_s ***tab_all, struct player_s *player);
void my_runner(char **map, sfRenderWindow *window, \
struct game_object_s ***tab_all, struct player_s *player);
void map_already_set(char **av, struct game_object_s ***tab_all, \
struct player_s *player);
void init_struct(struct game_object_s ***tab_all, char **map);
sfMusic *set_music_back(void);
int my_getnbr2(char const *str);
void change_high_score(int score, int hight_score, char *filepath);
char *get_high_score(char *filepath);
char *difficulty_menu(sfRenderWindow *window, \
struct player_s *player, struct game_object_s ***tab_all);
void music_destroy(sfSound **music, sfSoundBuffer **buffer);
sfSound **set_my_music(sfSoundBuffer **buffer);
bool handle_close_menu(bool go_back, sfEvent event);
int detect_click_player(int res_click, sfEvent event, \
struct player_s **skin, int nb_elem);
void free_skin(struct player_s **skin);
bool handle_event_skin(sfRenderWindow *window, struct player_s **skin, \
int *res_click);
void change_skin(int skin, struct player_s *player);
struct player_s **create_skin(void);
int display_skin(struct player_s **skin, sfRenderWindow *window, \
int start_display, struct player_s *player);
sfText *create_text(char *str, sfColor color, int scale, sfVector2f pos);
sfText **set_text(void);
void display_text_skin(sfText **text, int nb_text, sfRenderWindow *window);
void change_skin(int skin, struct player_s *player);
int manage_click(sfMouseButtonEvent mouse, struct game_object_s **tab_btn, \
int nb_elem, int *size);
int anim_player_run(struct player_s *player, float compt);
int skin_menu(int skin, sfRenderWindow *window,                  \
struct player_s *player, struct game_object_s ***tab_all);
int detect_click(sfEvent event, struct game_object_s **tab_btn, \
int nb_elem, int *size);
void home(sfRenderWindow *window, struct game_object_s ***tab_all, \
struct player_s *player);
char *int_to_str(int n);
sfText *set_score(int score);
void display_score(sfText *txt, int score, sfRenderWindow *window);
int define_pos_win(char **map);
void player_win(int *pos_x, struct player_s *ply);
void display_all(sfRenderWindow *window, \
struct game_object_s ***tab_all, struct player_s *player, char **map);
void collide_all(sfRenderWindow *window, \
struct game_object_s ***tab_all, struct player_s *player, char **map);
void anim_all(struct game_object_s ***tab_all, char **map);
void player_dead(sfRenderWindow *window, struct game_object_s ***tab_all);
void monster_collide(struct player_s *player, \
struct game_object_s ***tab_all, char **map, sfRenderWindow *window);
void bomb_collide(struct player_s *player, \
struct game_object_s ***tab_all, char **map, sfRenderWindow *window);
void remove_elem_map(char **map, int i, char c);
void remove_elem_tab(int i, int nb_piece, struct game_object_s **tab_obj);
void piece_collide(struct player_s *player, \
struct game_object_s **tab_obj, char **map, sfSound **music);
int get_nb_bomb(char **map);
void anim_bomb(struct game_object_s **tab_obj, char **map);
void anim_monster(struct game_object_s **tab_obj, char **map);
void display_all_bomb(struct game_object_s **tab_m, \
sfRenderWindow *window, char **map);
void display_all_monster(struct game_object_s **tab_m,  \
sfRenderWindow *window, char **map);
struct game_object_s **create_bomb(char **map);
struct game_object_s **create_monster(char **map);
int get_nb_monster(char **map);
void end_of_line(int *tab_index, char **map);
int get_nb_col(char *buffer);
int get_nb_piece(char **map);
int fs_open_file(char *filepath);
char **get_map(char *filepath);
int my_strlen(char *str);
void anim_piece(struct game_object_s **tab_obj, char **map);
void display_all_piece(struct game_object_s **tab_obj, \
sfRenderWindow *window, char **map);
struct game_object_s **create_piece(char **map);
void pause_game(sfEvent event, sfRenderWindow *window);
void jump(struct player_s *player);
void detect_jump(struct player_s *player, sfEvent event, sfSound **music);
void display_player(struct player_s *player, sfRenderWindow *window);
struct player_s *fill_player(char *filepath, sfVector2f pos);
void all_struct_bg(struct game_object_s ***tab_all);
struct game_object_s *create_object(const char *path_to_sprite_sheet, \
sfVector2f pos, sfIntRect rect);
void display_background(sfRenderWindow *window, \
struct game_object_s **array_bg);
void window_close(sfRenderWindow *window, sfEvent event);
sfRenderWindow *init_window(void);
int help(char **av);

#endif /* RUNNER_H_ */
